/*
** sdl_user.c for user in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri Apr  9 13:38:59 2010 anthony1 corbacho
** Last update Tue Apr 20 20:04:47 2010 anthony1 corbacho
*/

#include <stdlib.h>

#include "sdl_function.h"
#include "sdl_structure.h"
#include "sdl_function_next.h"
#include "sdl_user.h"
#include "sdl_user_actions.h"
#include "xsdl.h"

#include "map.h"
#include "map_initialize.h"
#include "my_rand.h"
#include "user.h"
#include "lmy_printf.h"

void			init_rect_player(SDL_Rect *pos, int x,
					 int y, t_sdl *sdl)
{
  (*pos).x = (x - sdl->scrollX) * MAP_W;
  (*pos).y = (y - sdl->scrollY) * MAP_H + HEADER_MENU + 50;
  (*pos).h = SPRITE_H;
  (*pos).w = SPRITE_W;
}

void			put_sprite_playerg(SDL_Rect *sdl, SDL_Rect *pos,
					   int indice)
{
  (*sdl).x = (*pos).x + (SPRITE_H * indice);
  (*sdl).y = (*pos).y - SPRITE_W;
  (*sdl).h = SPRITE_H;
  (*sdl).w = SPRITE_W;
}

void		action_for_user(t_sdl *sdl, t_sdl_user *user)
{
  if (user->bcast == 1)
    {
      put_song_bcast(sdl, user->x, user->y);
      user->bcast = 0;
    }
  if (user->inca == 1)
    put_incantation(sdl, user->x, user->y);
}

void		sdl_user_sprite(t_sdl *sdl, t_sdl_user *user,
				SDL_Rect rct_pos, int i2)
{
  init_rect_player(&rct_pos, user->x, user->y, sdl);
  put_sprite_playerg(&sdl->game.pos_player, &rct_pos, 1);
  sdl_update_sprite(&sdl->game.rect_player, i2, 0);
}

/*
** Here, put and make animation for each player ont the map,
** bcast, incant, movement.
** [STATIC] raison: animation for each player [loop in the player img]
*/
void		put_users(t_sdl *sdl)
{
  t_sdl_user	*user;
  SDL_Rect	rct_pos;
  static int	i = 0;
  int		i2;

  SDL_mutexP(sdl->elem->mut_user);
  user = sdl->elem->user;
  while (user)
    {
      i2 = i;
      if (user->team != NULL &&
	  (user->x >= sdl->scrollX && user->y >= sdl->scrollY))
	{
	  action_for_user(sdl, user);
	  sdl_user_sprite(sdl, user, rct_pos, i2);
	  xSDL_BlitSurface(sdl->game.player, &sdl->game.rect_player,
			  SDL_GetVideoSurface(), &sdl->game.pos_player);
	  if (++i2 > 47)
	    i2 = 0;
	}
      user = user->next;
    }
  if (++i > 47)
    i = 0;
  SDL_mutexV(sdl->elem->mut_user);
}
