/*
** player_cmd_gr.c for zappy in /home/damien/work_local/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Apr 13 14:40:38 2010 damien1 coppel
** Last update Sun Apr 25 18:23:01 2010 damien1 coppel
*/

#include <stdlib.h>
#include "action_gr.h"
#include "lstr.h"
#include "lmy.h"
#include "str_utils.h"
#include "server.h"
#include "position.h"
#include "map.h"

/*
** must receive : "bct X Y\n"
*/
char	*cmd_gr_get_case(char *arg)
{
  t_pos	*pos;
  char	*coordinate;
  int	len_arg;

  arg[my_strlen(arg)] = '\n';
  len_arg = my_strlen(arg);
  if (len_arg >= 8)
    {
      if (check_for_space(arg + 4))
	{
	  pos = extract_coordinates_from_str(arg + 4);
	  if (pos->x >= 0 && pos->x < map_size.x &&
	      pos->y >= 0 && pos->y < map_size.y)
	    {
	      coordinate = del_bn(extract_coordinates_from_pos(pos));
	      free(pos);
	      if (my_strlen(arg) == (my_strlen(coordinate) + 5))
		return (map_case_content_gr(arg));
	    }
	}
    }
  return (my_strdup("sbp\n"));
}

/*
** must receive : "sst T\n"
*/
char	*cmd_gr_set_time(char *arg)
{
  int	len_arg;
  int	val;
  char	*t;

  len_arg = my_strlen(arg);
  if (len_arg >= 5)
    {
      val = my_atoi(arg + 4);
      if (!val)
	return (my_strdup("sbp\n"));
      t = my_sprintf(val);
      if (my_strlen(arg) == my_strlen(t) + 4)
	{
	  free(t);
	  return (time_modif_unit_gr(val));
	}
    }
  return (my_strdup("sbp\n"));
}

/*
** must receive : "ppo #n\n"
*/
char		*cmd_gr_player_pos(char *arg)
{
  t_client	*client;

  if (arg[4] == '#')
    {
      client = get_client_by_id(my_atoi(arg + 5));
      if (client)
	return (player_pos_gr(client));
    }
  return (my_strdup("sbp\n"));
}

/*
** must receive : "plv #n\n"
*/
char	*cmd_gr_player_lvl(char *arg)
{
  t_client	*client;

  if (arg[4] == '#')
    {
      client = get_client_by_id(my_atoi(arg + 5));
      if (client)
	return (player_level_gr(client));
    }
  return (my_strdup("sbp\n"));
}

/*
** must receive : "pin #n\n"
*/
char	*cmd_gr_player_inv(char *arg)
{
  t_client	*client;

  if (arg[4] == '#')
    {
      client = get_client_by_id(my_atoi(arg + 5));
      if (client)
	return (player_inventaire_gr(client));
    }
  return (my_strdup("sbp\n"));
}
