/*
** expulse.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:49:25 2010 damien1 coppel
** Last update Sat Apr 24 14:02:32 2010 damien1 coppel
*/

#include "lstr.h"
#include "lmy_printf.h"
#include "lxsys.h"

#include <stdlib.h>

#include "action.h"
#include "action_gr.h"
#include "ip_protocol.h"
#include "process_clients.h"
#include "str_utils.h"
#include "map.h"
#include "message.h"

void	move_other_player(t_client *cl, t_client *victime)
{
  if (cl->orientation == 2)
    victime->pos.x = (victime->pos.x + 1) % map_size.x;
  else if (cl->orientation == 3)
    {
      if (victime->pos.y)
        --victime->pos.y;
      else
        victime->pos.y = map_size.y - 1;
    }
  else if (cl->orientation == 1)
    victime->pos.y = (victime->pos.y + 1) % map_size.y;
  else if (!cl->orientation)
    {
      if (victime->pos.x)
        --victime->pos.x;
      else
        victime->pos.x = map_size.x - 1;
    }
}

int	same_pos(t_pos *sender_pos, t_pos *victim_pos)
{
  if ((sender_pos->x == victim_pos->x) &&
      (sender_pos->y == victim_pos->y))
    return (1);
  return (0);
}

char	*expulse(t_client *cl, __attribute__((unused)) t_request *req)
{
  t_list	*cur;
  t_client	*client;
  char		*to_send;
  char		*orientation;

  send_to_graph(player_expulse_gr(cl));
  cur = vars->list_clients;
  orientation = my_sprintf(cl->orientation);
  while (cur)
    {
      client = ((t_client*)(cur->data));
      if ((cl->id != client->id) && same_pos(&(cl->pos), &(client->pos)))
        {
	  move_other_player(cl, client);
	  send_to_graph(player_pos_gr(client));
	  to_send = xmalloc(sizeof(*to_send) * 1024);
	  my_strcpy(to_send, "deplacement ");
	  my_strcat(my_strcat(to_send, orientation), "\n");
	  client->to_send_len += my_strlen(to_send);
	  client->to_send = dupcat(client->to_send, to_send);
        }
      cur = cur->next;
    }
  free(orientation);
  return (my_strdup(OK));
}
