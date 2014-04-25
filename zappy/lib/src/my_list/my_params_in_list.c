/*
** my_params_in_list.c for my_params_in_list in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Thu Nov  5 14:29:20 2009 damien1 coppel
*/

#include "my.h"
#include <stdlib.h>
#include "s_list.h"
#include "my_list.h"

int		add_begin_list(t_list **liste, void *data)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  new->data = data;
  new->next = *liste;
  *liste = new;
  return (0);
}

t_list		*my_params_in_list(int ac, char **av)
{
  t_list	*liste;
  int		i;

  i = 0;
  liste = 0;
  while (i < ac)
    {
      add_begin_list(&liste, av[i]);
      ++i;
    }
  return (liste);
}
