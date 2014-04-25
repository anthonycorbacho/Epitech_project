/*
** sdl_movement_radar.c for put the radar on map in /home/anthony/Zappy/
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Apr 12 21:22:18 2010 anthony1 corbacho
** Last update Tue Apr 20 17:18:40 2010 pierre1 rolland
*/

#include		"sdl_structure.h"
#include		"sdl_function.h"
#include		"xsdl.h"
#include		"sdl_function_next.h"
#include		"sdl_put_monster_minimap.h"

void			get_size_aff(t_sdl *sdl, int *x, int *y)
{
  if (map_size.x > 17)
    *x = sdl->screen_h;
  else
    *x = map_size.x * 64;
  if (map_size.y > 12)
    *y = sdl->screen_w;
  else
    *y = map_size.y * 64;
}

void			count_size(int *w, int xaff, int *h, int yaff)
{
  *w = (xaff * 156) / (map_size.x * 64);
  if (*w < 10)
    *w = 10;
  *h = (yaff * 110) / (map_size.y * 64);
  if (*h < 10)
    *h = 10;
}

void			event_radar(t_sdl *sdl)
{
  int			xaff;
  int			yaff;
  int			w;
  int			h;
  static int		first = 1;

  get_size_aff(sdl, &xaff, &yaff);
  count_size(&w, xaff, &h, yaff);
  if (first)
    {
      sdl->radar.screen_radar = SDL_CreateRGBSurface(SDL_HWSURFACE, w, h,
						     32, 0, 0, 0, 0);
      SDL_FillRect(sdl->radar.screen_radar, NULL,
		   SDL_MapRGB(sdl->screen->format, 255, 255, 255));
      SDL_SetAlpha(sdl->radar.screen_radar, SDL_SRCALPHA, 75);
      first = 0;
    }
  sdl->radar.rect_radar.x = (sdl->scrollX * w * 64) / xaff + 920;
  sdl->radar.rect_radar.y = (sdl->scrollY * h * 64) / yaff + 42;
  xSDL_BlitSurface(sdl->radar.screen_radar, NULL, sdl->screen,
		  &sdl->radar.rect_radar);
  put_monster_minimap(sdl);
}
