/*
** team_management_2.c for team_management in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Apr  9 17:42:19 2010 mathieu1 lornac
** Last update Mon Apr 12 17:53:13 2010 mathieu1 lornac
*/

#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "server.h"
#include "process_clients.h"

/*
** Returns 1 if the team name is allowed on the server
** 0 otherwise
*/
int		is_a_registered_team(char *name)
{
  t_team	**team;

  team = vars->team_list;
  while (*team && my_strcmp((*team)->team_name, name))
    ++team;
  return (*team != NULL);
}

/*
** Returns a pointer on the team corresponding to the
** specified name
*/
t_team		*get_team_by_name(char *name)
{
  t_team	**team;

  team = vars->team_list;
  while (*team && my_strcmp((*team)->team_name, name))
    ++team;
  return (*team);
}
