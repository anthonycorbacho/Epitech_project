/*
** sdl_print_invent.c for sdl in /home/pierre/Epitech/Projects/Zappy/
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Mon Apr 19 18:47:35 2010 pierre1 rolland
** Last update Sun Apr 25 16:11:28 2010 anthony1 corbacho
*/

#include	"user.h"
#include	"sdl_structure.h"

#include	"sdl_function.h"

#include	"sdl_content_case.h"
#include	"xsdl.h"

#include	"lstr.h"
#include	"lmy_printf.h"

void		print_inv_img(t_sdl *sdl, int y)
{
  int		i;

  i = 0;
  while (i < 7)
    {
      sdl->invsurf.rect_inv.x = 27 * i;
      sdl->invsurf.rect_inv.y = 0;
      sdl->invsurf.rect_inv.w = 27;
      sdl->invsurf.rect_inv.h = 27;
      sdl->invsurf.pos_inv.x = 605 + 50 * (i % 4);
      sdl->invsurf.pos_inv.y = y - 11 + 22 * (i / 4);
      xSDL_BlitSurface(sdl->invsurf.inv, &sdl->invsurf.rect_inv,
		       sdl->screen, &sdl->invsurf.pos_inv);
      i++;
    }
}

void		print_inv_num(t_sdl *sdl, int y, t_sdl_user *user)
{
  int		i;
  char		*nbr;

  i = 0;
  while (i < 7)
    {
      if (i == 0)
	nbr = my_sprintf(user->inventaire.food);
      else
	nbr = my_sprintf(user->inventaire.rocks[i - 1]);
      put_text(nbr, 632 + 50 * (i % 4), y - 9 + 22 * (i / 4), sdl);
      free(nbr);
      i++;
    }
}
