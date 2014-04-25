#include <limits.h>
#include <stdlib.h>

#include "fromlib.h"

#include "attributs.h"
#include "display_commons.h"
#include "formats.h"
#include "displays.h"
#include "get_len_modif.h"

#define llong long long

/*
** Return a char * containing the value expressed in the specified base
** base > 1
*/
char		*my_sprintfs(llong nb, char *base)
{
  char		*ret;
  int		i;
  llong		power;
  llong		lmax;

  if (nb == LLONG_MIN)
    return (pf_strdup("9223372036854775808"));
  nb = (nb < 0) ? (-nb) : (nb);
  lmax = LLONG_MAX / pf_strlen(base);
  power = 1;
  i = 1;
  while (((power = (power * pf_strlen(base))) < nb) && (power < lmax))
    ++i;
  ret = pf_xmalloc(sizeof(*ret) * (i + 1));
  (!(nb / power)) ? (power /= pf_strlen(base)) : (42);
  i = 0;
  while (power)
    {
      ret[i++] = base[nb / power];
      nb %= power;
      power /= pf_strlen(base);
    }
  ret[i] = 0;
  return (ret);
}

/*
**Displays the signe of the number
*/
int		disp_signe(long long nb, int signe, int doit)
{
  if (nb < 0)
    {
      if (doit)
	pf_putchar('-');
      return (1);
    }
  else if (signe & att_plus)
    {
      if (doit)
	pf_putchar('+');
      return (1);
    }
  else if (signe & att_space)
    {
      if (doit)
	pf_putchar(' ');
      return (1);
    }
  return (0);
}

/*
**Retrieves the number from the arg
**returns a long long
*/
llong		translate_nb(void *arg, int mod)
{
  llong		nb;

  if (mod & mod_ll_v)
      nb = *((long long *)arg);
  else if (mod & mod_l_v)
    nb = *((long *) arg);
  else if (mod & mod_h_v)
    nb = *((short *) arg);
  else if (mod & mod_hh_v)
    nb = *((char *) arg);
  else
    nb = *((int *) arg);
    return (nb);
}

char		*int_prep(t_format *f, llong *nb, void *arg, int *i)
{
  char		base[] = decimal_base;
  char		*str;

  *nb = translate_nb(arg, f->len_modif);
  str = my_sprintfs(*nb, base);
  f->attribut = treat_attributes_num(f->attribut, f->precision);
  str = add_precision(str, f->precision);
  if (f->precision < 0)
    f->precision = 0;
  if (f->attribut & att_minus)
    {
      *i += pf_strlen(str) + disp_signe(*nb, f->attribut, 1);
      pf_putstr(str);
      *i += filled_width(f->field_width, *i, f->attribut, 1);
    }
  return (str);
}

/*
** Displays an integer
** arg is a pointer on the type
*/
int		display_int(void *arg, t_format *f)
{
  llong		nb;
  char		*str;
  int		i;

  i = 0;
  str = int_prep(f, &nb, arg, &i);
  if (!(f->attribut & att_minus))
    {
      i += disp_signe(nb, f->attribut, 0) + pf_strlen(str);
      if (f->attribut & att_zero)
	{
	  disp_signe(nb, f->attribut, 1);
	  i += filled_width(f->field_width, i, f->attribut, 1);
	}
      else
	{
	  i += filled_width(f->field_width, i, f->attribut, 1);
	  disp_signe(nb, f->attribut, 1);
	}
      pf_putstr(str);
    }
  free(str);
  return (i);
}

