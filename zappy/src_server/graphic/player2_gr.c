/*
** player2_gr.c for zappy
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 16:05:41 2010 damien1 coppel
** Last update Sat Apr 24 14:03:17 2010 damien1 coppel
*/

#include "server.h"
#include "position.h"
#include "str_utils.h"
#include "lstr.h"
#include "lxsys.h"
#include "server.h"
#include "action_gr.h"

/*
** Sends all the players connected :
** "pnw #n X Y O L N\n"
*/
char		*player_all_connect_gr()
{
  t_list	*cur;
  char		*to_send;

  to_send = 0;
  cur = vars->list_clients;
  while (cur)
    {
      to_send = dupcat(to_send, player_connect_gr((t_client*)(cur->data)));
      cur = cur->next;
    }
  return (to_send);
}

/*
** connection of new player :
** "pnw #n X Y O L N\n"
*/
char		*player_connect_gr(t_client *client)
{
  char		*to_send;
  char		*coor;
  char		*p_num;
  char		*ori;
  char		*lvl;

  if (!client->team_name)
    return (NULL);
  coor = del_bn(extract_coordinates_from_pos(&(client->pos)));
  p_num = my_sprintf(client->id);
  ori = my_sprintf(client->orientation);
  lvl = my_sprintf(client->level);
  to_send = xmalloc(13 + my_strlen(p_num) + my_strlen(coor)
		    + my_strlen(client->team_name));
  my_strcpy(to_send, "pnw #");
  my_strcat(my_strcat(my_strcat(my_strcat(to_send, p_num), " "), coor), " ");
  if (!client->orientation)
    my_strcat(to_send, "4");
  else
    my_strcat(to_send, ori);
  my_strcat(my_strcat(to_send, " "), lvl);
  my_strcat(my_strcat(my_strcat(to_send, " "), client->team_name), "\n");
  xfree_n(coor, p_num, ori, lvl, (void *)-1);
  return (to_send);
}

/*
** Position of a player :
** "ppo #n X Y O\n"
*/
char		*player_pos_gr(t_client *client)
{
  char		*to_send;
  char		*coordinate;
  char		*player_num;
  char		*ori;
  int		len;

  coordinate = del_bn(extract_coordinates_from_pos(&(client->pos)));
  player_num = my_sprintf(client->id);
  ori = my_sprintf(client->orientation);
  len = 13 + my_strlen(player_num) + my_strlen(coordinate) +
    my_strlen(client->team_name);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "ppo #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, " ");
  my_strcat(to_send, coordinate);
  my_strcat(to_send, " ");
  if (!client->orientation)
    my_strcat(to_send, "4");
  else
    my_strcat(to_send, ori);
  my_strcat(to_send, "\n");
  xfree_n(coordinate, player_num, ori, (void *)-1);
  return (to_send);
}

/*
** Level of a player
** plv #n L\n
*/
char		*player_level_gr(t_client *client)
{
  char		*to_send;
  char		*player_num;
  char		*player_level;
  int		len;

  player_num = my_sprintf(client->id);
  player_level = my_sprintf(client->level);
  len = 8 + my_strlen(player_num) + my_strlen(player_level);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "plv #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, " ");
  my_strcat(to_send, player_level);
  my_strcat(to_send, "\n");
  free(player_num);
  free(player_level);
  return (to_send);
}

/*
** Player expulses
** pex #n\n
*/
char		*player_expulse_gr(t_client *client)
{
  char		*to_send;
  char		*player_num;
  int		len;

  player_num = my_sprintf(client->id);
  len = 7 + my_strlen(player_num);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "pex #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, "\n");
  return (to_send);
}
