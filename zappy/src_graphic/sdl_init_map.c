/*
** sdl_init_map.c for print the mao in the surface in /home/anthony/Zappy/
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Apr 12 13:53:26 2010 anthony1 corbacho
** Last update Tue Apr 20 16:25:30 2010 pierre1 rolland
*/

#include <stdlib.h>

#include "sdl_function.h"
#include "sdl_structure.h"
#include "sdl_function_next.h"
#include "xsdl.h"

void		update_map(t_sdl *sdl, SDL_Rect *pos, int x, int y)
{
  up_date_position(pos, x - sdl->scrollX, y - sdl->scrollY);
  if (x != sdl->mousex || y != sdl->mousey)
    {
      sdl_update_grass(&sdl->game.rect_game, 0, 0);
      xSDL_BlitSurface(sdl->game.screen_game, &sdl->game.rect_game,
		      sdl->screen, pos);
    }
  else
    {
      sdl_update_grass(&sdl->game_select.rect_game, 0, 0);
      xSDL_BlitSurface(sdl->game_select.screen_game,
		      &sdl->game_select.rect_game,
		      sdl->screen, pos);
    }
}

/*
** Print on the map the grass [prepare the surface ans blit]
*/
void		print_init_map(t_sdl *sdl)
{
  SDL_Rect	screen_pos;
  int		x;
  int		y;

  x = sdl->scrollX;
  init_rect(&screen_pos);
  screen_pos.h = SCREEN_H;
  screen_pos.w = SCREEN_W;
  while (x < map_size.x && x - sdl->scrollX < SCREEN_H / 64)
    {
      y = sdl->scrollY;
      while (y < map_size.y && y - sdl->scrollY < (SCREEN_W - 192) / 64)
	{
	  update_map(sdl, &screen_pos, x, y);
	  y++;
	}
      x++;
    }
}
