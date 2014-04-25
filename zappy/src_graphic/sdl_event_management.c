/*
** sdl_event_management.c for manag the event in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Apr 12 16:26:33 2010 anthony1 corbacho
** Last update Tue Apr 20 18:55:36 2010 anthony1 corbacho
*/

#include "sdl_function.h"
#include "movement.h"

#include "put_menu_items.h"
#include "sdl_content_case.h"
#include "sdl_monsters_case.h"

#include "lmy_printf.h"

void		treat_event_kd(t_sdl *sdl, SDL_Event event)
{
  int		cpt;

  cpt = 0;
  if (event.type == SDL_KEYDOWN)
    {
      while (list_key[cpt].sdlk_key != 0)
	{
	  if (event.key.keysym.sym == list_key[cpt].sdlk_key)
	    list_key[cpt].f(sdl);
	  ++cpt;
	}
      put_menu_items_sdl(sdl);
    }
}

void		event_management(t_sdl *sdl)
{
  SDL_Event	event;
  int		halt;
  int		xm;
  int		ym;

  halt = 1;
  xm = 0;
  ym = 0;
  event_content_case(sdl, 0, 192);
  while (halt)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	halt = 0;
      if (event.type == SDL_MOUSEMOTION)
	{
	  xm = event.button.x;
	  ym = event.button.y;
	  get_number_monster_on_cell(sdl, xm / 64, (ym - 192) / 64, 1);
	}
      treat_event_kd(sdl, event);
      event_content_case(sdl, xm, ym);
      event_monsters_case(sdl, xm, ym);
    }
}
