/*
** avance.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:47:17 2010 damien1 coppel
** Last update Tue Apr 20 10:20:28 2010 damien1 coppel
*/

#include <stdlib.h>

#include "lstr.h"
#include "action.h"
#include "action_gr.h"
#include "map.h"
#include "message.h"

char		*avance(t_client *cl, __attribute__((unused)) t_request *req)
{
  if (cl->orientation == 2)
    cl->pos.x = (cl->pos.x + 1) % map_size.x;
  else if (cl->orientation == 1)
    {
      if (cl->pos.y)
	cl->pos.y = (cl->pos.y - 1) % map_size.y;
      else
	cl->pos.y = map_size.y - 1;
    }
  else if (cl->orientation == 3)
    cl->pos.y = (cl->pos.y + 1) % map_size.y;
  else if (cl->orientation == 0)
    {
      if (cl->pos.x)
	cl->pos.x = (cl->pos.x - 1) % map_size.x;
      else
	cl->pos.x = map_size.x - 1;
    }
  send_to_graph(player_pos_gr(cl));
  return (my_strdup(OK));
}
