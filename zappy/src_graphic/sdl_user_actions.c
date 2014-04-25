/*
** sdl_user_actions.c for user actions in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr 14 19:33:22 2010 anthony1 corbacho
** Last update Sun Apr 25 18:35:12 2010 anthony1 corbacho
*/

#include <stdlib.h>

#include "sdl_function.h"
#include "sdl_structure.h"
#include "sdl_function_next.h"
#include "sdl_user.h"

#include "xsdl.h"

#include "map.h"
#include "map_initialize.h"
#include "my_rand.h"
#include "user.h"
#include "lmy_printf.h"

int		put_song_bcast(t_sdl *sdl, int x, int y)
{
  FSOUND_SAMPLE	*turkey;

  FSOUND_Init(44100, 32, 0);
  sdl->game.rec.x = (x - sdl->scrollX) * MAP_W + 30;
  sdl->game.rec.y = (y - sdl->scrollY) * MAP_H + HEADER_MENU + 10;
  sdl->game.rec.h = 17;
  sdl->game.rec.w = 17;
  xSDL_BlitSurface(sdl->game.bcast, NULL, sdl->screen, &sdl->game.rec);
  SDL_UpdateRects(sdl->screen, 1, &sdl->game.rec);
  if ((turkey = FSOUND_Sample_Load(FSOUND_FREE, "src_graphic/sound/gobble.wav",
				   0, 0, 0)) == NULL)
    {
      my_printf("Warning: Sound loading failled\n");
      SDL_Delay(1000);
      return (0);
    }
  FSOUND_PlaySound(FSOUND_FREE, turkey);
  SDL_Delay(1000);
  FSOUND_Sample_Free(turkey);
  FSOUND_Close();
  return (1);
}

void		sdl_up_incantation(SDL_Rect *rec, int indice, int position)
{
  (*rec).x = INCA_X * indice;
  (*rec).y = INCA_Y * position;
  (*rec).w = INCA_X;
  (*rec).h = INCA_Y;
}

/*
** Manage incantation animations
*/
void		put_incantation(t_sdl *sdl, int x, int y)
{
  SDL_Surface	*inca;
  SDL_Rect	pos;
  SDL_Rect	rect_inca;
  int		i;

  i = 0;
  inca = initialise_surface("src_graphic/img/inca.png");
  pos.x = (x - sdl->scrollX) * MAP_W + 25;
  pos.y = (y - sdl->scrollY) * MAP_H + HEADER_MENU + 25;
  pos.h = 25;
  pos.w = 32;
  sdl_up_incantation(&rect_inca, i, 0);
  xSDL_BlitSurface(inca, &rect_inca,
		  sdl->screen, &pos);
  i++;
  if (i > 16)
    i = 0;
  SDL_FreeSurface(inca);
}
