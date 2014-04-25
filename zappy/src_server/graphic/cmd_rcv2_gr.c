/*
** cmd_rcv2_gr.c for zappouille in /home/damien/work/zappybibici
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Thu Apr 22 15:34:51 2010 damien1 coppel
** Last update Thu Apr 22 15:37:58 2010 damien1 coppel
*/

#include <stdlib.h>
#include "action_gr.h"
#include "lstr.h"
#include "lmy.h"
#include "str_utils.h"
#include "server.h"
#include "position.h"
#include "map.h"

t_client	*get_client_by_id(int id)
{
  t_list	*cur;
  t_client	*client;

  cur = vars->list_clients;
  while (cur)
    {
      client = ((t_client*)(cur->data));
      if (client->id == id)
	return (client);
      cur = cur->next;
    }
  return (0);
}

int		check_for_space(char *str)
{
  while (*str)
    {
      if (*str == ' ')
	return (1);
      ++str;
    }
  return (0);
}
