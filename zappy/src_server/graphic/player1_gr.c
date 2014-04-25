/*
** player1_gr.c for zappy
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 16:04:52 2010 damien1 coppel
** Last update Sun Apr 25 19:40:21 2010 mathieu1 lornac
*/

#include "server.h"
#include "position.h"
#include "str_utils.h"
#include "lstr.h"
#include "lxsys.h"
#include "server.h"
#include "action_gr.h"

/*
** List the rocks according to that form:
** q q q q q q
*/
int		list_rocks_gr(t_client *client, char *to_send, int set)
{
  int	i;
  char	*tmp;
  int	s;

  s = 0;
  i = -1;
  while (++i < NB_ROCKS)
    {
      tmp = my_sprintf(client->rocks[i]);
      s += my_strlen(tmp) + 1;
      if (set)
	{
	  to_send = my_strcat(to_send, " ");
	  my_strcat(to_send, tmp);
	}
      free(tmp);
    }
  return (s);
}

/*
** Inventary of a player
** pin #n X Y q q q q q q q\n
*/
char		*player_inventaire_gr(t_client *client)
{
  char		*to_send;
  char		*coordinate;
  char		*player_num;
  char		*nb_food;
  int		i;

  to_send = 0;
  coordinate = del_bn(extract_coordinates_from_pos(&(client->pos)));
  player_num = my_sprintf(client->id);
  nb_food = my_sprintf(client->life);
  i = 21 + my_strlen(player_num) + my_strlen(coordinate)
    + my_strlen(nb_food) + list_rocks_gr(client, to_send, 0);
  to_send = xmalloc(i * sizeof(*to_send));
  my_strcpy(to_send, "pin #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, " ");
  my_strcat(to_send, coordinate);
  my_strcat(to_send, " ");
  my_strcat(to_send, nb_food);
  list_rocks_gr(client, to_send, 1);
  xfree_n(coordinate, player_num, nb_food, (void *)-1);
  my_strcat(to_send, "\n");
  return (to_send);
}

/*
** Player sends a broadcast
** pbc #n M\n
*/
char		*player_broadcast_gr(t_client *client, char *message)
{
  char		*to_send;
  char		*player_num;
  int		len;

  player_num = my_sprintf(client->id);
  len = 8 + my_strlen(player_num) + my_strlen(message);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "pbc #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, " ");
  my_strcat(to_send, message);
  my_strcat(to_send, "\n");
  free(player_num);
  return (to_send);
}

/*
** The player lays an egg
** enw #e #n X Y\n
*/
char		*player_lay_egg_gr(t_client *client, int egg_id)
{
  char		*to_send;
  char		*coordinate;
  char		*player_num;
  char		*egg_num;
  int		len;

  coordinate = extract_coordinates_from_pos(&(client->pos));
  player_num = my_sprintf(client->id);
  egg_num = my_sprintf(egg_id);
  len = 9 + my_strlen(player_num) + my_strlen(egg_num)
    + my_strlen(coordinate);
  to_send = xmalloc(len);
  my_strcpy(to_send, "enw #");
  my_strcat(to_send, egg_num);
  my_strcat(to_send, " #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, " ");
  my_strcat(to_send, coordinate);
  xfree_n(coordinate, player_num, egg_num, (void *)-1);
  return (to_send);
}

/*
** the player die because he has no more food
** pdi #n\n
*/
char		*player_die_hungry_gr(t_client *client)
{
  char		*to_send;
  char		*player_num;
  int		len;

  player_num = my_sprintf(client->id);
  len = 7 + my_strlen(player_num);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "pdi #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, "\n");
  free(player_num);
  return (to_send);
}
