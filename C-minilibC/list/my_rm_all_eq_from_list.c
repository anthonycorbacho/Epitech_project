
#include		"my_list_basics.h"

int			my_rm_all_eq_from_list(t_list **begin,
					       void *data_ref,
					       int (*cmp)())
{
  t_list		*curr;
  t_list		*last;

  curr = *begin;
  while (*begin && curr == *begin)
    if (!cmp(curr->data, data_ref))
      {
	*begin = my_remove_head(curr);
	curr = *begin;
      }
    else
      curr = (*begin)->next;
  last = *begin;
  if (*begin)
    {
      curr = last->next;
      while(curr)
	{
	  if (!cmp(curr->data, data_ref))
	      my_remove_right(last);
	  else
	    last = last->next;
	  curr = last->next;
	}
    }
}
