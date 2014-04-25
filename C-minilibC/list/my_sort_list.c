#include "my_list_basics.h"

void			my_char_swapping(void **c, void **c1)
{
  void			*t;

  t = *c;
  *c = *c1;
  *c1 = t;
}

int			my_sort_list(t_list **begin, int (*cmp)())
{
  int			i;
  int			ordered;

  if (!*begin)
    return (0);
  ordered = 0;
  while (!ordered)
    {
      i = 0;
      ordered = 1;
      while (go_to_elt_nb(*(begin), i + 1))
        {
          if (cmp((go_to_elt_nb(*(begin), i))->data,
		  (go_to_elt_nb(*(begin), i + 1))->data) > 0)
            {
              ordered = 0;
              my_char_swapping(&(go_to_elt_nb(*(begin), i)->data),
			       &(go_to_elt_nb(*(begin), i + 1)->data));
            }
	  i++;
        }
    }  
  return (0);
}
