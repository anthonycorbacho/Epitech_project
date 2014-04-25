/*
** my_put_elem_in_sort_list.c for put_e_s in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Tue Oct 20 18:30:13 2009 damien1 coppel
*/

#include "s_list.h"
#include "my.h"
#include "my_list.h"
#include <stdlib.h>

int		my_put_elem_in_sort_list(t_list **begin,void *data,
					 int (*cmp)())
{
  t_list	*new;

  new = malloc(sizeof(*new));
  new->data = data;
  new->next = *begin;
  *begin = new;
  my_sort_list(begin, cmp);
  return (0);
}
