/*
** my_list_size.c for my_list_size in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Tue Oct 20 18:18:30 2009 damien1 coppel
*/

#include "my.h"
#include "s_list.h"
#include "my_list.h"

int		my_list_size(t_list *begin)
{
  int		i;

  i = 0;
  while (begin != 0)
    {
      ++i;
      begin = begin->next;
    }
  return (i);
}
