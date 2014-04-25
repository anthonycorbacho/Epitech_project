/*
** user.h for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Thu Apr  8 16:37:12 2010 matias1 hastaran
** Last update Mon Apr 19 17:26:53 2010 anthony1 corbacho
*/

#ifndef __USER_H__
#define __USER_H__

#include	"structure_server.h"

/*
** Inventaire
*/
typedef struct		s_sdl_invent
{
  int			food;
  int			rocks[6];
}			t_sdl_invent;
/*
** User element
*/
typedef struct		s_sdl_user
{
  int			num;
  int			level;
  int			x;
  int			y;
  int			direction;
  int			bcast;
  int			inca;
  char			*team;
  struct s_sdl_invent	inventaire;
  struct s_sdl_user	*next;
}			t_sdl_user;

int			add_lvl_and_start_inc(int, t_elem *);

#endif	/* __USER_H__ */
