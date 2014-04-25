/*
** sdl_function_next.c for next function in /home/anthony/Zappy/
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr  7 18:29:11 2010 anthony1 corbacho
** Last update Tue Apr 20 16:18:02 2010 pierre1 rolland
*/

#include <stdlib.h>

#include "lmy_printf.h"
#include "sdl_function.h"
#include "xsdl.h"
#include "map_initialize.h"

/*
** Initialise SDL_Rect attribut to 0
*/
void		init_rect(SDL_Rect *rect)
{
  rect->x = 0;
  rect->y = 0;
  rect->h = 0;
  rect->w = 0;
}

/*
** Inisialise a new SDL_Surface, and load the image.
** If the background == blue -> set background to transparency
*/
SDL_Surface		*initialise_surface(char *sprite)
{
  SDL_Surface		*surface;

  surface = NULL;
  if ((surface = IMG_Load(sprite)) == NULL)
    {
      my_printf("Cant load Sprite: img %s failled\n", sprite);
      exit (1);
    }
  SDL_SetColorKey(surface, SDL_SRCCOLORKEY,
		  SDL_MapRGB(surface->format,0, 0, 255));
  return (surface);
}

/*
** Function that update the position of the cuted img between 2 SDL_Rect
*/
void			put_sprite_item(SDL_Rect *sdl, SDL_Rect *pos,
					int indice)
{
  (*sdl).x = (*pos).x + (ITEM_W * indice);
  (*sdl).y = (*pos).y + ITEM_W + 15;
  (*sdl).h = ITEM_W;
  (*sdl).w = ITEM_H;
}

void			put_sprite_player(SDL_Rect *sdl, SDL_Rect *pos,
					  int indice)
{
  (*sdl).x = (*pos).x + (SPRITE_W * indice);
  (*sdl).y = (*pos).y;
  (*sdl).h = SPRITE_H;
  (*sdl).w = SPRITE_W;
}

/*
** Function: Free all surface of the sdl structure.
*/
void			free_struct_sdl(t_sdl *sdl)
{
  SDL_FreeSurface(sdl->map);
  SDL_FreeSurface(sdl->screen);
  SDL_FreeSurface(sdl->player.player);
  SDL_FreeSurface(sdl->food.food);
  SDL_FreeSurface(sdl->rocks.rock);
  SDL_FreeSurface(sdl->game.screen_game);
  SDL_FreeSurface(sdl->game.item);
  SDL_FreeSurface(sdl->game.player);
  SDL_FreeSurface(sdl->menu.screen_menu);
  SDL_FreeSurface(sdl->radar.screen_radar);
  SDL_FreeSurface(sdl->egg.sdl_egg);
  SDL_FreeSurface(sdl->game.bcast);
  SDL_FreeSurface(sdl->game.updown);
}
