/*
** team_management.h for team management in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 18:02:53 2010 mathieu1 lornac
** Last update Fri Apr  9 18:22:59 2010 mathieu1 lornac
*/

#ifndef __TEAM_MANAGEMENT_H__
#define __TEAM_MANAGEMENT_H__

int		get_nb_players_on_team(char *s);
int		get_nb_players_max_on_team(char *name);
t_team		**init_teams(char **team_names, int team_nb, int team_size);
void		free_teams(t_team **t);

/*
** Returns 1 if the team name is allowed on the server
** 0 otherwise
*/
int		is_a_registered_team(char *name);

/*
** Returns a pointer on the team corresponding to the
** specified name
*/
t_team		*get_team_by_name(char *name);

#endif /*__TEAM_MANAGEMENT_H__*/
