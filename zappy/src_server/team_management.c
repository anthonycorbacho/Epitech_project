/*
** team_managment.c for team gestion in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 17:25:14 2010 mathieu1 lornac
** Last update Sat Apr 24 14:02:02 2010 damien1 coppel
*/

#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "server.h"
#include "process_clients.h"

/*
** Returns the nb of players on the specified team
*/
int		get_nb_players_on_team(char *s)
{
  int		members;
  t_client	*cl;
  t_list	*l;

  members = 0;
  l = vars->list_clients;
  while (l)
    {
      cl = l->data;
      if (cl->team_name && !my_strcmp(cl->team_name, s))
	members++;
      l = l->next;
    }
  return (members);
}

/*
** Get the number of players on the team
*/
int		get_nb_players_max_on_team(char *name)
{
  t_team	**team;

  team = vars->team_list;
  while (*team && my_strcmp((*team)->team_name, name))
    ++team;
  if (*team)
    return ((*team)->max_team_size);
  return (0);
}

/*
** Initalises the team structure
*/
t_team		**init_teams(char **team_names, int team_nb, int team_size)
{
  int		i;
  t_team	**teams;

  teams = xmalloc(sizeof(*teams) * (team_nb + 1));
  i = -1;
  while (++i < team_nb)
    {
      teams[i] = xmalloc(sizeof(**teams));
      teams[i]->team_name = team_names[i];
      teams[i]->max_team_size = team_size;
    }
  teams[i] = NULL;
  free(team_names);
  return (teams);
}

/*
** Liberates all the team structures
*/
void		free_teams(t_team **t)
{
  t_team	**teams;
  int		i;

  teams = t;
  i = -1;
  while (teams[++i])
    free(teams[i]);
  free(t);
}
