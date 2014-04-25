
#include <stdlib.h>
#include "llist.h"

void			free_list(t_list *l)
{
  t_list		*tmp;

  while (l && l->next)
    {
      tmp = l;
      l = l->next;
      free(tmp);
    }
  if (l)
    {
      free(l);
    }
}
