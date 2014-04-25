/*
** sdl_function_next.h for next function in /home/anthony/Zappy_home/zappy_2012s_coppel_a
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr  7 18:31:48 2010 anthony1 corbacho
** Last update Fri Apr  9 14:40:10 2010 anthony1 corbacho
*/

#ifndef __SDL_FUNCTION_NEXT_H__
#define __SDL_FUNCTION_NEXT_H__

void            init_rect(SDL_Rect *);
SDL_Surface	*initialise_surface(char *);
void		put_sprite_item(SDL_Rect *, SDL_Rect *, int);
void		put_sprite_player(SDL_Rect *, SDL_Rect *, int);
void		init_window_sprite(t_sdl *);
void		free_struct_sdl(t_sdl *);

#endif /*__SDL_FUNCTION_NEXT_H__*/
