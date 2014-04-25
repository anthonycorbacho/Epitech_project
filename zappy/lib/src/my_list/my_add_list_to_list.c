/*
** my_add_list_to_list.c for add_list in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Wed Oct 21 20:57:47 2009 damien1 coppel
*/

#include "s_list.h"
#include "my.h"
#include "my_list.h"

int		my_add_list_to_list(t_list **begin1,t_list *begin2)
{
  t_list	*save;

  if (*begin1 == 0)
    {
      *begin1 = begin2;
      return (0);
    }
  save = *begin1;
  while ((*begin1)->next != 0)
    (*begin1) = (*begin1)->next;
  (*begin1)->next = begin2;
  *begin1 = save;
  return (0);
}
