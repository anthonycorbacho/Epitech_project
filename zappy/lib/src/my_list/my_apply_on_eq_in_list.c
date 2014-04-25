/*
** my_apply_on_eq_in_list.c for apply_eq in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Tue Oct 20 18:13:35 2009 damien1 coppel
*/

#include "my.h"
#include "s_list.h"
#include "my_list.h"

int		my_apply_on_eq_in_list(t_list *begin, int (*f)(),
				       void *data_ref, int (*cmp)())
{
  t_list	*list_ptr;

  list_ptr = begin;
  while (list_ptr != 0)
    {
      if (cmp(list_ptr->data,data_ref) == 0)
	f(list_ptr->data);
      list_ptr = list_ptr->next;
    }
  return (0);
}
