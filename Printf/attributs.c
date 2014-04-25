#include "fromlib.h"

#include "attributs.h"

int		get_attribut(char *s)
{
  int		pos;

  pos = 0;
  while (*s && pf_char_is_in_base(*s, att_sequence) != -1)
    {
      pos |= (1 << pf_char_is_in_base(*s, att_sequence));
      pf_shift_left(s, 1);
    }
  return (pos);
}
