#include <stdlib.h>

#include "fromlib.h"

#include "attributs.h"
#include "display_commons.h"
#include "formats.h"
#include "displays.h"

/*
** Retrieves the string
*/
char		*get_string(void *s)
{
  return (*((char **) s));
}

/*
** Cuts the string at the precision size
*/
char		*cut_string(char *s, t_format *f)
{
  char		*ret;

  if (s == NULL)
    return (pf_strdup("(null)"));
  if (f->precision < 0)
    f->precision = pf_strlen(s);
  if (f->convertion == 'c' && f->precision == 0)
    f->precision = 1;
  ret = pf_xmalloc(sizeof(*ret) * (f->precision + 1));
  pf_strncpy(ret, s, f->precision);
  ret[f->precision] = 0;
  if (f->convertion == 'c')
    free(s);
  return (ret);
}

/*
** Displays normally the string if conv == s
** Display octal values of non printable char if conv == S
*/
int		disp_str(char *s, char conv)
{
  int		len;

  len = pf_strlen(s);
  if (conv == 's' || conv == 'c')
    pf_putstr(s);
  else
    while (*s)
      {
	if (pf_char_isprintable(*s))
	  pf_putchar(*s);
	else
	  {
	    pf_putchar('\\');
	    pf_putchar(((*s & (7 << 6)) >> 6) + 48);
	    pf_putchar(((*s & (7 << 3)) >> 3) + 48);
	    pf_putchar((*s & 7) + 48);
	  }
	++s;
      }
  return (len);
}

/*
** String display
** 1st par: pointer on a char *
** 2nd par: pointer on a format struct
*/
int		display_str(void *s, t_format *f)
{
  char		*str;
  int		occur;

  occur = 0;
  f->attribut = treat_attributes_str(f->attribut);
  if (f->convertion == 'c')
    {
      str = malloc(sizeof(*str) * 2);
      str[0] = (*(char *)(s));
      str[1] = 0;
    }
  else
    str = get_string(s);
  if (f)
    {
      str = cut_string(str, f);
      if (!((f->attribut & att_minus) && f->field_width))
	occur += filled_width(f->field_width, pf_strlen(str), f->attribut, 1);
      occur += disp_str(str, f->convertion);
      if (!(!(f->attribut & att_minus) && f->field_width))
	occur += filled_width(f->field_width, pf_strlen(str), f->attribut, 1);
      free(str);
    }
  else
    occur += disp_str(str, f->convertion);
  return (occur);
}
