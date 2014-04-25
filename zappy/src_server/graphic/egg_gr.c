/*
** egg_gr.c for zappy in /home/damien/work_local/zappy_2012s_co/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 16:03:35 2010 damien1 coppel
** Last update Sat Apr 24 14:03:00 2010 damien1 coppel
*/

#include "server.h"
#include "position.h"
#include "str_utils.h"
#include "lstr.h"
#include "lxsys.h"
#include "egg_management.h"
#include "action_gr.h"

/*
** Sends all the players connected :
** "pnw #n X Y O L N\n"
*/
char		*egg_all_on_map_gr()
{
  char		*to_send;
  t_list	*cur;
  t_egg		*egg;

  to_send = 0;
  cur = vars->egg_list;
  while (cur)
    {
      egg = ((t_egg*)(cur->data));
      to_send = dupcat(to_send, egg_laid_on_case_gr(egg->client, egg));
      if (egg->status == 1)
	to_send = dupcat(to_send, egg_born_gr(egg));
      cur = cur->next;
    }
  return (to_send);
}

/*
** "enw #e #n X Y\n"
*/
char		*egg_laid_on_case_gr(t_client *client, t_egg *egg)
{
  char		*to_send;
  char		*coordinate;
  char		*player_num;
  char		*egg_num;
  int		len;

  coordinate = extract_coordinates_from_pos(&(egg->pos));
  player_num = my_sprintf(client->id);
  egg_num = my_sprintf(egg->id);
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

/*
** "eht #e\n"
*/
char	*egg_born_gr(t_egg *egg)
{
  char		*to_send;
  char		*egg_num;

  egg_num = my_sprintf(egg->id);
  to_send = xmalloc(7 + my_strlen(egg_num));
  my_strcpy(to_send, "eht #");
  my_strcat(to_send, egg_num);
  my_strcat(to_send, "\n");
  free(egg_num);
  return (to_send);
}

/*
** "ebo #e\n"
*/
char	*egg_player_connected_gr(t_egg *egg)
{
  char		*to_send;
  char		*egg_num;

  egg_num = my_sprintf(egg->id);
  to_send = xmalloc(7 + my_strlen(egg_num));
  my_strcpy(to_send, "ebo #");
  my_strcat(to_send, egg_num);
  my_strcat(to_send, "\n");
  free(egg_num);
  return (to_send);
}

/*
** "edi #e\n"
*/
char	*egg_born_die_hungry_gr(t_egg *egg)
{
  char		*to_send;
  char		*egg_num;

  egg_num = my_sprintf(egg->id);
  to_send = xmalloc(7 + my_strlen(egg_num));
  my_strcpy(to_send, "edi #");
  my_strcat(to_send, egg_num);
  my_strcat(to_send, "\n");
  free(egg_num);
  return (to_send);
}
