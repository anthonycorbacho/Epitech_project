#include <stdlib.h>

#include "fromlib.h"

#include "attributs.h"
#include "display_commons.h"
#include "formats.h"
#include "displays.h"

/*
** Writes width - done  chars
** The char written depends on the attribut
*/
int		filled_width(int width, int done , int attribut, int nb)
{
  char		c;
  int		occur;

  occur = width - done;
  if (occur < 0)
    {
      occur = 0;
      done = width;
    }
  if ((attribut & att_zero) && nb)
    c = '0';
  else
    c = ' ';
  while (done++ < width)
    pf_putchar(c);
  return (occur);
}

/*
**Adds the leading zeros to the number according to the precision field
*/
char		*add_precision(char *str, int precision)
{
  int		len;
  char		*ret;
  int		x;

  len = pf_strlen(str);
  if (precision == -1)
    precision = 0;
  if (len < precision)
    {
      ret = pf_xmalloc(sizeof(*ret) * (precision + 1));
      x = 0;
      while (x + len < precision)
	ret[x++] = '0';
      pf_strcpy(ret + x, str);
    }
  else
    return (str);
  free(str);
  return (ret);
}

/*
**Treats the attributs according to their priority
**Valable for d,i u,o,x,X options
*/
int		treat_attributes_num(int att, int precision)
{
  int		ret;

  ret = att;
  if (att & att_minus)
    ret &= ~att_zero;
  if (att & att_plus)
    ret &= ~att_space;
  if (precision != -1)
    ret &= ~att_zero;
  return (ret);
}

int		treat_attributes_str(int att)
{
  int		ret;

  ret = att;
  if (att & att_minus)
    ret &= ~att_zero;
  if (att & att_plus)
    ret &= ~att_space;
  return (ret);
}

/*
**Returns the base
*/
char		*select_base(char conv)
{
  if (conv == 'o')
    return (octal_base);
  else if (conv == 'x' || conv == 'p')
    return (hexa_base);
  else if (conv == 'X')
    return (HEXA_base);
  else if (conv == 'u')
    return (decimal_base);
  else if (conv == 'b')
    return (binary_base);
  else
    return (NULL);
}
