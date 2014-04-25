/*
** my_rm_all_eq_from_list.c for rm_all_eq in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Wed Oct 21 21:36:35 2009 damien1 coppel
*/

#include "my.h"
#include <stdlib.h>
#include "s_list.h"
#include "my_list.h"

t_list		*rm_all_start(t_list **begin, void *data_ref,
			      int (*cmp)())
{
  t_list	*to_rm;
  t_list	*save;

  save = *begin;
  while (save != 0 && cmp(save->data, data_ref) == 0)
    {
      to_rm = save;
      save = save->next;
      free(to_rm);
    }
  return (save);
}

int		my_rm_all_eq_from_list(t_list **begin, void *data_ref,
				       int (*cmp)())
{
  t_list	*save;
  t_list	*to_rm;

  if (*begin == 0)
    return (0);
  *begin = rm_all_start(begin, data_ref, cmp);
  if (*begin == 0)
    return (0);
  save = *begin;
  to_rm = save->next;
  while (to_rm != 0)
    {
      if (cmp(to_rm->data, data_ref) == 0)
        {
          save->next = to_rm->next;
          free(to_rm);
          to_rm = save->next;
        }
      else
        {
          save = to_rm;
          to_rm = to_rm->next;
        }
    }
  return (0);
}
