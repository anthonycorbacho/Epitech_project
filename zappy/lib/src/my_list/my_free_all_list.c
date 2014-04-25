/*
** my_free_all_list.c for free_list in /home/coppel_a/work/lib/my_list
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Thu Nov  5 13:43:18 2009 damien1 coppel
** Last update Thu Apr 22 14:43:17 2010 mathieu1 lornac
*/

#include "my.h"
#include "s_list.h"
#include "my_list.h"
#include <stdlib.h>

int		my_free_all_list(t_list *begin)
{
  t_list	*list_tmp;

  while (begin != 0)
    {
      list_tmp = begin->next;
      free(begin->data);
      free(begin);
      begin = list_tmp;
    }
  return (0);
}

int		my_free_all_list_struct(t_list *begin)
{
  t_list	*list_tmp;

  while (begin != 0)
    {
      list_tmp = begin->next;
      free(begin);
      begin = list_tmp;
    }
  return (0);
}
