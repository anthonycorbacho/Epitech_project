/*
** forky.c<2> for fork in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Apr  9 18:28:35 2010 mathieu1 lornac
** Last update Sat Apr 10 17:04:27 2010 mathieu1 lornac
*/

#include "action_gr.h"
#include "lxsys.h"
#include "lmy.h"
#include "lstr.h"
#include "position.h"

/*
** The player forks
** pfk #e\n
*/
char	*player_fork_gr(t_client *client)
{
  char		*to_send;
  char		*player_num;

  player_num = my_sprintf(client->id);
  to_send = xmalloc(7 + my_strlen(player_num));
  my_strcpy(to_send, "pfk #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, "\n");
  free(player_num);
  return (to_send);
}

/*
** The player fork is done
** enw #e #n X Y\n
*/
char	*player_end_fork_gr(t_client *client, int id_egg)
{
  char		*to_send;
  char		*coordinate;
  char		*player_num;
  char		*egg_num;
  int		len;

  coordinate = extract_coordinates_from_pos(&(client->pos));
  player_num = my_sprintf(client->id);
  egg_num = my_sprintf(id_egg);
  len = 9 + my_strlen(egg_num) + my_strlen(player_num) + my_strlen(coordinate);
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
