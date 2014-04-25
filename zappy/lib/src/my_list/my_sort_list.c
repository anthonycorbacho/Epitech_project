/*
** my_sort_list.c for my_sort_list in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Tue Oct 20 18:29:31 2009 damien1 coppel
*/

#include "s_list.h"
#include "my.h"
#include "my_list.h"

t_list		*got_s(t_list *list, int elem)
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

int		my_sort_list(t_list **begin,int (*cmp)())
{
  int		i;
  int		j;
  int		size;

  size = my_list_size(*begin);
  i = 0;
  while (i < size)
    {
      j = i + 1;
      while (j < size)
        {
	  if (cmp(got_s(*begin,i)->data, got_s(*begin,j)->data) > 0)
            {
	      my_swap(&(got_s(*begin,i)->data), &(got_s(*begin,j)->data));
              j = i;
            }
          j++;
        }
      i++;
    }
  return (0);
}
