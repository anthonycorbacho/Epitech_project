/*
** broadcast.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:48:23 2010 damien1 coppel
** Last update Sun Apr 25 15:11:31 2010 mathieu1 lornac
*/

#include "lstr.h"
#include "lmy_printf.h"

#include <stdlib.h>

#include "action.h"
#include "action_gr.h"
#include "ip_protocol.h"
#include "process_clients.h"
#include "str_utils.h"
#include "message.h"

#define ABS(Value) ((Value < 0) ? (-Value) : (Value))

/*
** calcul the case where the message come from as if the player
** looking on the left
*/
int		calc_dir_if_look_left(int dx, int dy, int abs_dx, int abs_dy)
{
  int		ret;

  ret = 0;
  if (abs_dx == abs_dy)
    {
      if (dx > 0 && dy > 0)
	ret = 8;
      if (dx > 0 && dy < 0)
	ret = 2;
      if (dx < 0 && dy > 0)
	ret = 6;
      if (dx < 0 && dy < 0)
	ret = 4;
    }
  if (dx > 0 && (abs_dy < abs_dx))
    ret = 1;
  else if (dx < 0 && (abs_dy < abs_dx))
    ret = 5;
  else if (dy > 0 && (abs_dx < abs_dy))
    ret = 7;
  else if (dy < 0 && (abs_dx < abs_dy))
    ret = 3;
  return (ret);
}

/*
** return where the message come from
*/
int		calc_provenance(t_pos *src, t_pos *dst, int orientation)
{
  int		dx;
  int		dy;
  int		abs_dx;
  int		abs_dy;
  int		ret;

  ret = 0;
  dx = dst->x - src->x;
  dy = dst->y - src->y;
  abs_dx = ABS(dx);
  abs_dy = ABS(dy);
  if (dx == 0 && dy == 0)
    return (0);
  ret = calc_dir_if_look_left(dx, dy, abs_dx, abs_dy);
  ret += 2 * orientation;
  if (ret > 8)
    ret %= 8;
  return (ret);
}

/*
** Send the broadcast message to the client
*/
void		send_broacast_to_cl(t_client *cl, t_client *client, char *mess)
{
  char		*to_send;
  char		*come_from;

  if (cl->id != client->id)
    {
      come_from = my_sprintf(calc_provenance(&(cl->pos),
					     &(client->pos),
					     client->orientation));
      to_send = malloc(sizeof(*to_send) * (my_strlen(mess) + 12));
      my_strcpy(to_send, "message ");
      my_strcat(to_send, come_from);
      my_strcat(to_send, ",");
      my_strcat(to_send, mess);
      my_strcat(to_send, "\n");
      client->to_send_len += my_strlen(to_send);
      client->to_send = dupcat(client->to_send, to_send);
      free(come_from);
    }
}

char		*broadcast(t_client *cl, t_request *req)
{
  t_list	*cur;
  t_client	*client;
  char		**param;

  param = my_str_sep(req->request, " ");
  if (!param[1])
    {
      free (param);
      return (my_strdup(KO));
    }
  cur = vars->list_clients;
  while (cur)
    {
      client = ((t_client*)(cur->data));
      send_broacast_to_cl(cl, client, param[1]);
      cur = cur->next;
    }
  send_to_graph(player_broadcast_gr(cl, del_bn(param[1])));
  free (param);
  return (my_strdup(OK));
}
