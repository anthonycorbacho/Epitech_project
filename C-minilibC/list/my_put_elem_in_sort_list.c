#include "my_list_basics.h"

int		my_put_elem_in_sort_list(t_list **begin, void *data, int (*cmp)())
{
  t_list	*elt;

  elt = malloc(sizeof(*elt));
  elt->data = data;
  *begin = my_insert_head(*begin, elt);
  my_sort_list(begin, cmp);
  return (0);
}
