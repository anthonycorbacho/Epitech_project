/*
** structure_server.h for structure of elem in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Apr 15 16:09:00 2010 anthony1 corbacho
** Last update Sat Apr 17 23:10:32 2010 pierre1 rolland
*/

#ifndef __STRUCTURE_SERVER_H__
#define __STRUCTURE_SERVER_H__

/*
** Eggs element
*/
typedef struct		s_sdl_egg
{
  int			num;
  int			x;
  int			y;
  int			status;
  struct s_sdl_egg	*next;
}			t_sdl_egg;

typedef struct		s_elem
{
  int			socket;
  int			actual_time_value;
  struct SDL_mutex	*mut_egg;
  struct SDL_mutex	*mut_user;
  struct s_sdl_user	*user;
  struct s_sdl_egg	*egg;
}			t_elem;

#endif /*__STRUCTURE_SERVER_H__*/
