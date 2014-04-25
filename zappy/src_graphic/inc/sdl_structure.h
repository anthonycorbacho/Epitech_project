/*
** sdl_structure.h for structure for sdl\ in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr  7 11:55:39 2010 anthony1 corbacho
** Last update Tue Apr 20 17:11:55 2010 pierre1 rolland
*/

#ifndef __SDL_STRUCTURE_H__
#define __SDL_STRUCTURE_H__

#include "fmod.h"
#include "SDL.h"

typedef struct		s_player_sdl
{
  SDL_Surface		*player;
  SDL_Rect		rect_player;
  SDL_Rect		pos_player;
}			t_sdl_player;

typedef struct		s_food_sdl
{
  SDL_Surface		*food;
  SDL_Rect		rect_food;
  SDL_Rect		pos_food;
}			t_sdl_food;

typedef struct		s_square_monster
{
  SDL_Surface		*square;
  SDL_Rect		pos;
}			t_square_monster;

typedef struct		s_minimonster_sdl
{
  SDL_Surface		*minimonster;
  SDL_Rect		rect_monster;
  SDL_Rect		pos_monster;
}			t_minimonster_sdl;

typedef struct		s_invsurf_sdl
{
  SDL_Surface		*inv;
  SDL_Rect		rect_inv;
  SDL_Rect		pos_inv;
}			t_invsurf_sdl;

typedef struct		s_rock_sdl
{
  SDL_Surface		*rock;
  SDL_Rect		rect_rock;
  SDL_Rect		pos_rock;
}			t_sdl_rock;

typedef struct		s_radar_sdl
{
  SDL_Surface		*screen_radar;
  SDL_Rect		rect_radar;
  SDL_Rect		pos_radar;
}			t_sdl_radar;

typedef struct		s_game_sdl
{
  SDL_Surface		*screen_game;
  SDL_Surface		*item;
  SDL_Surface		*player;
  SDL_Surface		*bcast;
  SDL_Surface		*updown;
  SDL_Rect		rec;
  SDL_Rect		rect_player;
  SDL_Rect		pos_player;
  SDL_Rect		rect_item;
  SDL_Rect		pos_item;
  SDL_Rect		rect_game;
  SDL_Rect		pos_game;
}			t_sdl_game;

typedef struct		s_menu_sdl
{
  SDL_Surface		*screen_menu;
  SDL_Rect		rect_menu;
  SDL_Rect		pos_menu;
}			t_sdl_menu;

typedef struct		s_user_scroll
{
  int			scrollY;
  int			scrollYmax;
}			t_user_scroll;

typedef struct		s_eggs_sdl
{
  SDL_Surface		*sdl_egg;
  SDL_Rect		pos_egg;
  SDL_Rect		rct_egg;
}			t_sdls_egg;

typedef struct			s_sdl
{
  int				scrollX;
  int				scrollY;
  int				screen_h;
  int				screen_w;
  int				mousex;
  int				mousey;
  SDL_Surface			*screen;
  SDL_Surface			*map;
  SDL_Rect			rec_map;
  struct s_menu_sdl		menu;
  struct s_radar_sdl		radar;
  struct s_game_sdl		game;
  struct s_game_sdl		game_select;
  struct s_player_sdl		player;
  struct s_food_sdl		food;
  struct s_rock_sdl		rocks;
  struct s_elem			*elem;
  struct s_user_scroll		scroll_users;
  struct s_eggs_sdl		egg;
  struct s_minimonster_sdl	minimonster;
  struct s_invsurf_sdl		invsurf;
  struct s_square_monster	square_monster;
}				t_sdl;

#endif /*__SDL_STRUCTURE_H__*/
