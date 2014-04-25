#include <stdlib.h>

#include "fromlib.h"

t_list			*pf_insert_head(t_list *list, t_list *elt)
{
  if (list == 0)
    {
      elt->next = 0;
      return (elt);
    }
  elt->next = list;
  return (elt);
}

void			pf_completely_free_list(t_list *l, void (*liberer)())
{
  t_list		*tmp;

  while (l && l->next)
    {
      tmp = l;
      l = l->next;
      liberer(tmp->data);
      free(tmp);
    }
  if (l)
    {
      liberer(l->data);
      free(l);
    }
}
