#include "fromlib.h"

#include "get_len_modif.h"

int		get_len_modif(char *s)
{
  char		*backup;
  char		modifs[3];
  int		i;

  backup = s;
  modifs[0] = 0;
  i = 0;
  while ((i < 3) && (pf_char_is_in_base(*s, modif_seq) != -1))
    {
      modifs[i++] = modif_seq[pf_char_is_in_base(*s, modif_seq)];
      ++s;
    }
  modifs[i] = 0;
  pf_shift_left(backup, i);
  if (!pf_strcmp(modifs, mod_ll))
    return (mod_ll_v);
  else if (!pf_strcmp(modifs, mod_l))
    return (mod_l_v);
  else if (!pf_strcmp(modifs, mod_hh))
    return (mod_hh_v);
  else if (!pf_strcmp(modifs, mod_h))
    return (mod_h_v);
  else
    return (mod_n);
}
