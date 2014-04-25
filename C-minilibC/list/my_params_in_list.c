
#include "my_list_basics.h"

t_list			*my_params_in_list(int ac,char **av)
{
  t_list		*elt;
  t_list		*list;
  int			i;

  i = 0;
  list = 0;
  while (i < ac)
    {
      elt = malloc(sizeof(*elt));
      elt->data = av[i];
      list = my_insert_head(list, elt);
      ++i;
    }
  return (list);
}
