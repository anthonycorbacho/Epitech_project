/*
** sdl_egg.h for header egg in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri Apr 16 18:13:03 2010 anthony1 corbacho
** Last update Fri Apr 16 18:15:05 2010 anthony1 corbacho
*/

#ifndef __SDL_EGG_H__
#define __SDL_EGG_H__

void		sdl_init_rect(SDL_Rect *, SDL_Rect *, t_sdl_egg *, t_sdl *);
void		sdl_update_egg(SDL_Rect *, int, int);
void		sdl_sprite_egg(SDL_Rect *, SDL_Rect *, int);
void		put_eggs(int, int, t_sdl *, SDL_Rect *);

#endif /*__SDL_EGG_H__*/
