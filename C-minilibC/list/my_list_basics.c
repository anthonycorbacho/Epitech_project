
#include "my_list_basics.h"

t_list			*my_insert_head(t_list *list, t_list *elt)
{
  if (list == 0)
    {
      elt->next = 0;
      return (elt);
    }
  elt->next = list;
  return (elt);
}

t_list			*my_remove_head(t_list *list)
{
  t_list		*tmp;

  tmp = list->next;
  free(list);
  return (tmp);
}

void			*my_remove_right(t_list *list)
{
  t_list		*tmp;

  if (list->next->next)
    {
      tmp = list->next;
      list->next = list->next->next;
      free(tmp);
    }
  else
    {
      tmp = list->next;
      list->next = 0;
      free(tmp);
    }
}

t_list                  *go_to_elt_nb(t_list *list, int nb)
{
  if (!list)
    return (0);
  while (--nb > 0)
    {
      if (list->next)
	list = list->next;
      else
	return (0);
    }
  return (list);
}
