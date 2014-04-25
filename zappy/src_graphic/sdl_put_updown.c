/*
** sdl_put_updown.c for up and down in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Apr 20 11:50:28 2010 anthony1 corbacho
** Last update Tue Apr 20 16:38:51 2010 pierre1 rolland
*/

#include		"sdl_structure.h"
#include		"user.h"

#include		"sdl_function.h"
#include		"sdl_function_next.h"

#include		"sdl_content_case.h"
#include		"put_menu_items.h"
#include		"put_menu_monster.h"

#include		"sdl_print_invent.h"

#include		"xsdl.h"

void			init_rect_updown(SDL_Rect *pos, int x, int y)
{
  (*pos).x = x;
  (*pos).y = y;
  (*pos).h = 7;
  (*pos).w = 12;
}

void			put_sprite_updown(SDL_Rect *sdl, SDL_Rect *pos,
					  int indice)
{
  (*sdl).x = (*pos).x + (7 * indice);
  (*sdl).y = (*pos).y - 12;
  (*sdl).h = 7;
  (*sdl).w = 12;
}

void			sdl_update_updown(SDL_Rect *rec, int indice,
					  int position)
{
  (*rec).x = 12 * indice;
  (*rec).y = 7 * position;
  (*rec).w = 12;
  (*rec).h = 7;
}

void			put_updown(t_sdl *sdl, int x, int y, int indice)
{
  SDL_Rect		pos;
  SDL_Rect		rct;
  SDL_Rect		pos_rct;

  init_rect(&pos);
  init_rect(&rct);
  init_rect(&pos_rct);
  init_rect_updown(&pos, x, y);
  put_sprite_updown(&pos_rct, &pos, indice);
  sdl_update_updown(&rct, indice, 0);
  xSDL_BlitSurface(sdl->game.updown, &rct,
		   sdl->screen, &pos_rct);
}
