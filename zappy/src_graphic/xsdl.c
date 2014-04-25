/*
** xsdl.c for function xsdl in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri Apr 16 19:10:24 2010 anthony1 corbacho
** Last update Tue Apr 20 16:40:07 2010 pierre1 rolland
*/

#include "SDL.h"
#include "lmy_printf.h"

int		xSDL_EnableKeyRepeat(int delay, int interval)
{
  int		ret;

  ret = 0;
  if ((ret = SDL_EnableKeyRepeat(delay, interval)) == -1)
    {
      my_printf("Error on SDL_EnableKey\n");
      exit(0);
    }
  return (ret);
}

int		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect)
{
  int		ret;

  ret = 0;
  if ((ret = SDL_BlitSurface(src, srcrect, dst, dstrect)) == -1)
    {
      my_printf("Error on SDL_BlitSurface\n");
      exit(0);
    }
  return (ret);
}

int		xSDL_Init(Uint32 flags)
{
  int		ret;

  ret = 0;
  if ((ret = SDL_Init(flags)) == -1)
    {
      my_printf("Error on SDL_Init\n");
      exit(0);
    }
  return (ret);
}
