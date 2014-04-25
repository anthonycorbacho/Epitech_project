/*
** xsdl.h for return sdl funcs in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Sat Apr 17 14:48:28 2010 anthony1 corbacho
** Last update Sat Apr 17 14:49:24 2010 anthony1 corbacho
*/

#ifndef __XSDL_H__
#define __XSDL_H__

int		xSDL_EnableKeyRepeat(int delay, int interval);
int		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect);
int		xSDL_Init (Uint32 flags);

#endif /*__XSDL_H__*/
