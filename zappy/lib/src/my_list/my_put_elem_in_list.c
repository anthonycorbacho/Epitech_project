/*
** my_put_elem_in_list.c for put_e_s in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 09:02:50 2009 damien1 coppel
** Last update Thu Nov  5 14:30:08 2009 damien1 coppel
*/

#include "s_list.h"
#include "my.h"
#include "my_list.h"
#include <stdlib.h>

int		my_put_elem_in_list(t_list **liste, void *data)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  new->data = data;
  new->next = *liste;
  *liste = new;
  return (0);
}
