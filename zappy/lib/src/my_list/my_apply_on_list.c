/*
** my_apply_on_list.c for my_apply_on_list in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Thu Nov  5 13:44:12 2009 damien1 coppel
*/

#include "my.h"
#include "s_list.h"
#include "my_list.h"

int		my_apply_on_list(t_list *begin, int (*f)())
{
  t_list	*list_ptr;

  list_ptr = begin;
  while (list_ptr != 0)
    {
      f(list_ptr->data);
      list_ptr = list_ptr->next;
    }
  return (0);
}
