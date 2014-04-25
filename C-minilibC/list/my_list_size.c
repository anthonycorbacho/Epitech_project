
#include "my_list_basics.h"

int			my_list_size(t_list *begin)
{
  int			s;
  
  s = 1;
  if (!begin)
    return (0);
  while (begin->next)
    {
      ++s;
      begin = begin->next;
    }
  return (s);
}
