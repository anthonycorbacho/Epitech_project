/*
** put_menu.c for put the header in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Sun Apr 11 02:27:05 2010 anthony1 corbacho
** Last update Tue Apr 20 16:16:10 2010 pierre1 rolland
*/

#include "sdl_function.h"
#include "sdl_structure.h"
#include "sdl_function_next.h"
#include "sdl_user.h"
#include "xsdl.h"

#include "map.h"
#include "map_initialize.h"

#include "lmy_printf.h"

void		put_menu_sprite(SDL_Rect *sdl)
{
  (*sdl).x = 0;
  (*sdl).y = 0;
  (*sdl).w = HEADER_MENU;
  (*sdl).h = SCREEN_W;
}

void		update_menu(SDL_Rect *rec)
{
  (*rec).x = 0;
  (*rec).y = 0;
  (*rec).w = HEADER_MENU * 6;
  (*rec).h = SCREEN_W;
}

/*
** put on the screen the header menu [Prepar the header img]
*/
void		put_menu_sdl(t_sdl *sdl)
{
  put_menu_sprite(&sdl->menu.pos_menu);
  update_menu(&sdl->menu.rect_menu);
  xSDL_BlitSurface(sdl->menu.screen_menu, &sdl->menu.rect_menu,
		  sdl->screen, &sdl->menu.pos_menu);
}
