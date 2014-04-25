/*
** fork.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:49:38 2010 damien1 coppel
** Last update Tue Apr 20 10:22:00 2010 damien1 coppel
*/

#include "lstr.h"

#include "action.h"
#include "action_gr.h"
#include "team_management.h"
#include "egg_management.h"
#include "message.h"

char		*forky(t_client *cl, __attribute__((unused))t_request *req)
{
  t_team	*team;
  int		id_egg;

  id_egg = new_egg(cl);
  team = get_team_by_name(cl->team_name);
  team->max_team_size++;
  send_to_graph(player_end_fork_gr(cl, id_egg));
  return (my_strdup(OK));
}
