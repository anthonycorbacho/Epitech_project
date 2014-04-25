#include <stdlib.h>

char			*convert_base(char *nbr, char *base_from, char *base_to)
{

  long long		nb;

  if (*nbr == '\0' || *base_from == '\0' || *base_to == '\0')
    return (0);
  nb = my_getnbr_base(nbr, base_from);
  return (nbr_base_tocharp(nb, base_to));
}
