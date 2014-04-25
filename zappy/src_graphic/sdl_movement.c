/*
** sdl_movement.c for movement for sdl event in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Apr  8 20:23:13 2010 anthony1 corbacho
** Last update Tue Apr 20 16:18:53 2010 pierre1 rolland
*/

#include "sdl_function.h"
#include "sdl_structure.h"
#include "sdl_function_next.h"

#include "map.h"
#include "map_initialize.h"

#include "lmy_printf.h"

/*
** Here, management of scrolling event
*/
void		event_up(t_sdl *sdl)
{
  sdl->scrollY -= 1;
  if (sdl->scrollY < 0)
    sdl->scrollY = 0;
}

void		event_down(t_sdl *sdl)
{
  (sdl->scrollY)++;
  if (map_size.y <= sdl->scrollY + ((SCREEN_W - HEADER_MENU) / MAP_H) - 2)
    sdl->scrollY--;
}

void		event_left(t_sdl *sdl)
{
  sdl->scrollX -= 1;
  if (sdl->scrollX < 0)
    sdl->scrollX = 0;
}

void		event_right(t_sdl *sdl)
{
  sdl->scrollX += 1;
  if (map_size.x <= sdl->scrollX + (SCREEN_H / MAP_W) - 1)
    sdl->scrollX--;
}
