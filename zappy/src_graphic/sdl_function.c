/*
** sdl_function.c for function for sdl in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr  7 13:19:52 2010 anthony1 corbacho
** Last update Tue Apr 20 16:17:52 2010 pierre1 rolland
*/

#include <stdlib.h>

#include "sdl_function.h"
#include "sdl_function_next.h"
#include "map_initialize.h"
#include "sdl_init_rect.h"
#include "xsdl.h"

#include "lmy_printf.h"

/*
** Function that updates the rect position on the sprite image
*/
void		sdl_update_grass(SDL_Rect *rec, int indice, int position)
{
  (*rec).x = MAP_W * indice;
  (*rec).y = MAP_H * position;
  (*rec).w = MAP_W;
  (*rec).h = MAP_H;
}

void		sdl_update_item(SDL_Rect *rec, int indice, int position)
{
  (*rec).x = ITEM_W * indice;
  (*rec).y = ITEM_H * position;
  (*rec).w = ITEM_W;
  (*rec).h = ITEM_H;
}

void		sdl_update_sprite(SDL_Rect *rec, int indice, int position)
{
  (*rec).x = SPRITE_W * indice;
  (*rec).y = SPRITE_H * position;
  (*rec).w = SPRITE_W;
  (*rec).h = SPRITE_H;
}

void		up_date_position(SDL_Rect *pos, int x, int y)
{
  (*pos).x = x * MAP_W;
  if (y < 0)
    y = 0;
  (*pos).y = y * MAP_H + 192;
}

/*
** Inisialise the window [video and sound]
** and all element of the sdl structure [surface, rect, ...]
*/
void		initialise_sdl_window(t_sdl *sdl)
{
  sdl->screen = NULL;
  xSDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  sdl->scrollX = 0;
  sdl->scrollY = 0;
  sdl->screen_h = 18 * 64;
  sdl->screen_w = 13 * 64;
  if ((sdl->screen = SDL_SetVideoMode(sdl->screen_h, sdl->screen_w,
				      32,
				      SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
      printf("Error initialization mode\n");
      exit(0);
    }
  SDL_WM_SetCaption(" ~>Zappy Graphic client", NULL);
  SDL_FillRect(sdl->screen, NULL,
	       SDL_MapRGB(sdl->screen->format, 255, 255, 255));
  initialise_rect_structure(sdl);
  initialise_surface_img(sdl);
}

