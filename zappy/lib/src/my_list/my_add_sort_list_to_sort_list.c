/*
** my_add_sort_list_to_sort_list.c for asl in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Tue Oct 20 18:31:07 2009 damien1 coppel
*/

#include "s_list.h"
#include "my.h"
#include "my_list.h"

int		my_add_sort_list_to_sort_list(t_list **begin1,t_list *begin2,
					      int (*cmp)())
{
  my_add_list_to_list(begin1, begin2);
  my_sort_list(begin1, cmp);
  return (0);
}
