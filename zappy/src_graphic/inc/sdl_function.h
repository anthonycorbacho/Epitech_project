/*
** sdl_function.h for function for sdl in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr  7 13:18:12 2010 anthony1 corbacho
** Last update Sun Apr 11 17:42:21 2010 anthony1 corbacho
*/

#ifndef __SDL_FUNCTION_H__
#define __SDL_FUNCTION_H__

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "sdl_structure.h"
#include "definitions.h"
#include "map.h"

#define SCREEN_W 900
#define SCREEN_H 1200

#define SPRITE_W 27
#define SPRITE_H 27

#define MSPRITE_W 27
#define MSPRITE_H 27

#define ITEM_W 32
#define ITEM_H 16

#define MAP_H 64
#define MAP_W 64

#define HEADER_MENU 192

void		sdl_update_sprite(SDL_Rect *, int, int);
void		sdl_update_grass(SDL_Rect *, int, int);
void            sdl_update_item(SDL_Rect *, int, int);
void		initialise_sdl_window(t_sdl *);
void		up_date_position(SDL_Rect *, int, int);


#endif /*__SDL_FUNCTION_H__*/
