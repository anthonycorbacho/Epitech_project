/*
** sdl_print_items.c for pritn items in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Apr 12 12:18:26 2010 anthony1 corbacho
** Last update Tue Apr 20 16:19:35 2010 pierre1 rolland
*/

#include "sdl_function.h"
#include "sdl_structure.h"
#include "sdl_function_next.h"
#include "structure_server.h"
#include "sdl_egg.h"

#include "xsdl.h"

#include "definitions.h"
#include "user.h"
#include "map.h"
#include "map_initialize.h"

void		put_item_user(int x, int y, t_sdl *sdl, SDL_Rect *pos)
{
  t_sdl_user	*usr;
  int		nb_usr_cell;

  usr = sdl->elem->user;
  nb_usr_cell = 0;
  while (usr)
    {
      if (usr->team != NULL)
	{
	  if (usr->x == x && usr->y == y)
	    nb_usr_cell++;
	}
      usr = usr->next;
    }
  if (nb_usr_cell > 0)
    {
      put_sprite_item(&sdl->game.pos_item, pos, 1);
      sdl_update_item(&sdl->game.rect_item,
		      (nb_usr_cell > 1) ? 1 : 2, 0);
      xSDL_BlitSurface(sdl->game.item, &sdl->game.rect_item,
		      sdl->screen, &sdl->game.pos_item);
    }
}

void		put_items(int x, int y,
			t_sdl *sdl, SDL_Rect *pos)
{
  t_map_elt	*map_elt;
  int		cpt;
  int		flag;

  flag = 0;
  map_elt = get_cell(x, y);
  if (map_elt->food != 0)
    flag += 1;
  cpt = 0;
  while (cpt < NB_ROCKS)
    {
      if (map_elt->rocks[cpt] != 0)
	flag += 1;
      cpt++;
    }
  if (flag > 0)
    {
      put_sprite_item(&sdl->game.pos_item, pos, 0);
      sdl_update_item(&sdl->game.rect_item, 0, 0);
      xSDL_BlitSurface(sdl->game.item, &sdl->game.rect_item,
		      sdl->screen, &sdl->game.pos_item);
    }
}

void		put_items_map(t_sdl *sdl)
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
	  up_date_position(&screen_pos, x - sdl->scrollX, y - sdl->scrollY);
	  put_items(x, y, sdl, &screen_pos);
	  put_item_user(x, y, sdl, &screen_pos);
	  put_eggs(x, y, sdl, &screen_pos);
	  y++;
	}
      x++;
    }
}
