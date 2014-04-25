/*
** player4_gr.c for zappy in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Tue Apr 13 19:31:58 2010 mathieu1 lornac
** Last update Tue Apr 13 19:51:53 2010 mathieu1 lornac
*/

#include "server.h"
#include "position.h"
#include "str_utils.h"
#include "lstr.h"
#include "lxsys.h"
#include "server.h"
#include "action_gr.h"

/*
** The player dies
** pdi #n\n
*/
char		*player_dies_gr(t_client *client)
{
  char		*to_send;
  char		*player_num;
  int		len;

  player_num = my_sprintf(client->id);
  len = 8 + my_strlen(player_num);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "pdi #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, "\n");
  free(player_num);
  return (to_send);
}
