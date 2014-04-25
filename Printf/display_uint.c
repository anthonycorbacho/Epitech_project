#include <limits.h>
#include <stdlib.h>

#include "fromlib.h"

#include "attributs.h"
#include "display_commons.h"
#include "formats.h"
#include "get_len_modif.h"
#include "displays.h"

#define ullong unsigned long long

/*
** Returns a char * containing the value expressed in the specified base
** nb HAS to be positive
** base > 1
*/
char		*my_sprintfu(ullong nb, char *base)
{
  char		*ret;
  int		i;
  int		baselen;
  ullong	power;
  ullong	lmax;

  baselen = pf_strlen(base);
  lmax = ULLONG_MAX / baselen;
  power = 1;
  i = 1;
  while (((power = (power * baselen)) < nb) && (power < lmax))
    ++i;
  ret = pf_xmalloc(sizeof(*ret) * (i + 1));
  (!(nb / power)) ? (power /= baselen) : (42);
  i = 0;
  while (power)
    {
      ret[i++] = base[nb / power];
      nb %= power;
      power /= baselen;
    }
  ret[i] = 0;
  return (ret);
}

/*
**Retrieves the number from the arg
**returns a ullong
*/
ullong		translate_unb(void *arg, int mod, char convert)
{
  ullong		nb;

  if ((mod & mod_ll_v) && (convert != 'p'))
    nb = *((ullong*)arg);
  else if (mod & mod_l_v)
    nb = *((unsigned long *) arg);
  else if (mod & mod_h_v)
    nb = *((unsigned short *) arg);
  else if (mod & mod_hh_v)
    nb = *((unsigned char *) arg);
  else
    nb = *((unsigned int *) arg);
  return (nb);
}

/*
**Displays the prefix
**returns the nb of char displayed
*/
int		disp_prefix(int attribut, char conv, int doit, char *str)
{
  if (attribut & att_sharp)
    {
      if (conv == 'x' || conv == 'p')
	{
	  (doit) ? pf_putstr("0x") : (42);
	  return (2);
	}
      if (conv == 'X')
	{
	  if (doit)
	    pf_putstr("0X");
	  return (2);
	}
      if (conv == 'o')
	{
	  if (str[0] != '0')
	    {
	      if (doit)
		pf_putchar('0');
	      return (1);
	    }
	  return (0);
	}
    }
  return (0);
}

void		uint_treatment(t_format *f, ullong nb, char *str)
{
  if (f->convertion == 'p')
    f->attribut |= att_sharp;
  if (nb == 0 && f->convertion != 'p')
    f->attribut &= ~att_sharp;
  if (nb == 0 && f->precision == 0)
    *str = 0;
}

/*
**Displays an unsigned integer
*/
int		display_uint(void *arg, t_format *f)
{
  ullong	nb;
  char		*str;
  char		*base;
  int		i;

  i = 0;
  base = select_base(f->convertion);
  f->attribut = treat_attributes_num(f->attribut, f->precision);
  nb = translate_unb(arg, f->len_modif, f->convertion);
  str = add_precision(my_sprintfu(nb, base), f->precision);
  uint_treatment(f, nb, str);
  if (f->attribut & att_minus)
    {
      i += pf_strlen(str) + disp_prefix(f->attribut, f->convertion, 1, str);
      pf_putstr(str);
      i += filled_width(f->field_width, i, f->attribut, nb != 0);
      free(str);
      return (i);
    }
  i += pf_strlen(str) + disp_prefix(f->attribut, f->convertion, 0, str);
  i += filled_width(f->field_width, i, f->attribut, nb != 0);
  disp_prefix(f->attribut, f->convertion, 1, str);
  pf_putstr(str);
  free(str);
  return (i);
}
