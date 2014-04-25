/*
** sdl_egg.c for namagement of eggs in /home/anthony/Zappy/
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri Apr 16 15:05:58 2010 anthony1 corbacho
** Last update Tue Apr 20 16:17:19 2010 pierre1 rolland
*/

#include <stdlib.h>

#include "sdl_function.h"
#include "sdl_structure.h"
#include "sdl_function_next.h"

#include "xsdl.h"

#include "map.h"
#include "map_initialize.h"
#include "structure_server.h"

void		sdl_update_egg(SDL_Rect *rct, int inc, int pos)
{
  (*rct).x = 17 * inc;
  (*rct).y = 17 * pos;
  (*rct).h = 17;
  (*rct).w = 17;
}

void		sdl_sprite_egg(SDL_Rect *pos, SDL_Rect *rct, int inc)
{
  (*pos).x = (*rct).x + (17 * inc) + 5;
  (*pos).y = (*rct).y + 10;
  (*pos).h = 17;
  (*pos).w = 17;
}

/*
** Put int the map cell sprite of egg
*/
void		put_eggs(int x, int y, t_sdl *sdl, SDL_Rect *pos)
{
  t_sdl_egg	*egg;
  int		cpt;

  SDL_mutexP(sdl->elem->mut_egg);
  egg = sdl->elem->egg;
  cpt = 0;
  while (egg)
    {
      if (egg->x == x && egg->y == y)
	cpt++;
      egg = egg->next;
    }
  if (cpt > 0)
    {
      sdl_sprite_egg(&sdl->egg.pos_egg, pos, 0);
      sdl_update_egg(&sdl->egg.rct_egg,
		     (cpt > 1) ? 1 : 0, 0);
      xSDL_BlitSurface(sdl->egg.sdl_egg, &sdl->egg.rct_egg,
		      sdl->screen, &sdl->egg.pos_egg);
    }
  SDL_mutexV(sdl->elem->mut_egg);
}
