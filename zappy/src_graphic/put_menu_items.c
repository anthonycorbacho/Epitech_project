/*
** put_menu_items.c for put_items in /home/pierre/Epitech/Projects/
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Tue Apr 13 13:27:32 2010 pierre1 rolland
** Last update Tue Apr 20 16:36:09 2010 pierre1 rolland
*/

#include	"sdl_function.h"
#include	"sdl_structure.h"
#include	"sdl_function_next.h"
#include	"sdl_user.h"
#include	"xsdl.h"

#include	"map.h"
#include	"map_initialize.h"

void		put_menu_items_sprite(SDL_Rect *sdl)
{
  (*sdl).x = 0;
  (*sdl).y = 0;
  (*sdl).w = 384;
  (*sdl).h = SCREEN_W;
}

void		update_menu_items(SDL_Rect *rec)
{
  (*rec).x = 0;
  (*rec).y = 0;
  (*rec).w = 384;
  (*rec).h = SCREEN_W;
}

void		put_menu_items_sdl(t_sdl *sdl)
{
  put_menu_items_sprite(&sdl->menu.pos_menu);
  update_menu_items(&sdl->menu.rect_menu);
  xSDL_BlitSurface(sdl->menu.screen_menu, &sdl->menu.rect_menu,
                  sdl->screen, &sdl->menu.pos_menu);
}
