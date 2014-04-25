/*
** my_rev_list.c for my_rev_list in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Tue Oct 20 18:37:20 2009 damien1 coppel
*/

#include "my.h"
#include "s_list.h"
#include "my_list.h"

t_list		*goto_elem(t_list *list, int elem)
{
  int		i;

  i = 0;
  while (i <elem)
    {
      list = list->next;
      ++i;
    }
  return (list);
}

int		my_rev_list(t_list **begin)
{
  t_list	*last;
  int		i;
  int		size;
  t_list	*save;

  i = 0;
  size = my_list_size(*begin);
  if (size == 0)
    return (0);
  last = *begin;
  while (last->next != 0)
    last = last->next;
  save = last;
  while (i < size)
    {
      last->next = goto_elem(*begin, size - i - 1);
      last = goto_elem(*begin, size - i - 1);
      ++i;
    }
  last->next = 0;
  *begin = save;
  return (0);
}
