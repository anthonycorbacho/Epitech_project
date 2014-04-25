/*
** egg_management.h for zappy in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sat Apr 10 14:37:44 2010 mathieu1 lornac
** Last update Sat Apr 24 14:02:13 2010 damien1 coppel
*/

#ifndef __EGG_MANAGEMENT_H__
#define __EGG_MANAGEMENT_H__

/*
** Egg structure
*/
typedef struct		s_egg
{
  int			id;		/*Egg identification*/
  int			status;		/*0: not hatch ,1: hatch(eclot)*/
  struct timeval	expiration_date;/*Expiration status*/
  char			*team_name;	/*Team which laid it*/
  t_client		*client;	/*player who created the egg*/
  t_pos			pos;		/*Egg pos*/
}			t_egg;

/*
** Creates a new egg associated whith the team name
*/
int	new_egg(t_client *cl);

/*
** Compares team names
*/
int	egg_team_name_cmp(t_egg *e1, t_egg *e2);

/*
** Remove an egg from the egg list
*/
void	remove_egg(int id_egg, int connected);

/*
** Checks if the egg status has expired
** Change it's status if necessary
** Removes it from the list if needed
*/
void	check_on_eggs();

/*
** Removes the egg with a player connected on if there is an
** egg available
*/
t_pos	*connect_player_on_egg(char *team_name);

#endif /*__EGG_MANAGEMENT_H__*/
