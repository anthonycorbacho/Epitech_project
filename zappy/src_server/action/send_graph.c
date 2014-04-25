/*
** send_graph.c for zappy in /home/damien/work_local/zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Thu Apr  8 17:45:32 2010 damien1 coppel
** Last update Sat Apr 24 14:02:47 2010 damien1 coppel
*/

#include <stdlib.h>
#include "lstr.h"
#include "str_utils.h"

#include "server.h"
#include "action.h"

/*
** Send information to the graphic client if there is one
*/
void		send_to_graph(char *to_send)
{
  if (vars->graphic_client && to_send)
    {
      vars->graphic_client->to_send_len += my_strlen(to_send);
      vars->graphic_client->to_send = dupcat(vars->graphic_client->to_send,
					     to_send);
    }
  else
    free(to_send);
}
