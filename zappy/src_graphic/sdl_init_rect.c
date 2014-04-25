/*
** sdl_init_rect.c for init rect elements in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Sat Apr 10 16:41:04 2010 anthony1 corbacho
** Last update Tue Apr 20 16:18:25 2010 pierre1 rolland
*/

#include <stdlib.h>

#include "lmy_printf.h"
#include "sdl_function.h"
#include "sdl_function_next.h"
#include "xsdl.h"
#include "map_initialize.h"

/*
** Initialisations the rect in the structure.
*/
void		initialise_rect_structure(t_sdl *sdl)
{
  init_rect(&sdl->rec_map);
  init_rect(&sdl->player.rect_player);
  init_rect(&sdl->food.rect_food);
  init_rect(&sdl->rocks.rect_rock);
  init_rect(&sdl->player.pos_player);
  init_rect(&sdl->food.pos_food);
  init_rect(&sdl->rocks.pos_rock);
  init_rect(&sdl->menu.rect_menu);
  init_rect(&sdl->menu.pos_menu);
  init_rect(&sdl->radar.rect_radar);
  init_rect(&sdl->radar.pos_radar);
  init_rect(&sdl->game.rect_game);
  init_rect(&sdl->game.pos_game);
  init_rect(&sdl->game.rect_item);
  init_rect(&sdl->game.pos_item);
  init_rect(&sdl->game.rect_player);
  init_rect(&sdl->game.pos_player);
}
/*
** Set the image on the Surface
*/
void		initialise_surface_img(t_sdl *sdl)
{
  sdl->map = initialise_surface("src_graphic/img/grass.bmp");
  sdl->player.player = initialise_surface("src_graphic/img/zappy.bmp");
  sdl->rocks.rock = initialise_surface("src_graphic/img/rock-food.bmp");
  sdl->food.food = initialise_surface("src_graphic/img/rock-food.bmp");
  sdl->game.screen_game = initialise_surface("src_graphic/img/grass.bmp");
  sdl->game_select.screen_game =
    initialise_surface("src_graphic/img/grass2.bmp");
  sdl->game.item = initialise_surface("src_graphic/img/item.png");
  sdl->game.player = initialise_surface("src_graphic/img/player.png");
  sdl->menu.screen_menu = initialise_surface("src_graphic/img/menu.png");
  sdl->radar.screen_radar = initialise_surface("src_graphic/img/rock-food.bmp");
  sdl->egg.sdl_egg = initialise_surface("src_graphic/img/egg.png");
  sdl->game.bcast = initialise_surface("src_graphic/img/bcast.png");
  sdl->minimonster.minimonster =
    initialise_surface("src_graphic/img/info_user.png");
  sdl->invsurf.inv = initialise_surface("src_graphic/img/invent.png");
  sdl->game.updown = initialise_surface("src_graphic/img/updown.png");
}
