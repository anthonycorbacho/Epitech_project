/*
** egg_management2.c for zappy in /home/coppel_a/work/c/zappy/src_server
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sat Apr 24 13:18:34 2010 damien1 coppel
** Last update Sat Apr 24 14:01:40 2010 damien1 coppel
*/

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "server.h"
#include "time_management.h"
#include "egg_management.h"
#include "team_management.h"
#include "action.h"
#include "action_gr.h"
#include "position.h"

/*
** Removes the egg with a player connected on if there is an
** egg available
*/
t_pos		*connect_player_on_egg(char *team_name)
{
  t_egg		ref;
  t_egg		*c;
  t_pos		*pos;

  pos = NULL;
  ref.team_name = team_name;
  c = my_find_elm_eq_in_list(vars->egg_list, &ref, egg_team_name_cmp);
  if (c)
    {
      pos = xmalloc(sizeof(*pos));
      set_pos(pos, &c->pos);
      send_to_graph(egg_player_connected_gr(c));
      remove_egg(c->id, 1);
    }
  return (pos);
}
