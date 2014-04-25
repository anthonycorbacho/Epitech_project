/*
** sdl_put_monster_minimap.c for sdl in /home/pierre/Epitech/Projects/Zappy/
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Tue Apr 20 17:06:56 2010 pierre1 rolland
** Last update Wed Apr 21 17:24:31 2010 pierre1 rolland
*/

#include	"user.h"
#include	"sdl_function.h"
#include	"sdl_function.h"
#include	"sdl_structure.h"
#include	"sdl_movement_radar.h"
#include	"xsdl.h"

void			put_monster_minimap(t_sdl *sdl)
{
  int			xaff;
  int			yaff;
  static int		first = 1;
  t_sdl_user		*user;

  user = sdl->elem->user;
  get_size_aff(sdl, &xaff, &yaff);
  if (first)
    {
      sdl->square_monster.square = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5,
							32, 0, 0, 0, 0);
      SDL_FillRect(sdl->square_monster.square, NULL,
                   SDL_MapRGB(sdl->screen->format, 255, 0, 0));
      first = 0;
    }
  while (user != NULL)
    {
      sdl->square_monster.pos.x = (user->x * 156) / map_size.x + 920;
      sdl->square_monster.pos.y = (user->y * 110) / map_size.y + 42;
      xSDL_BlitSurface(sdl->square_monster.square, NULL, sdl->screen,
		       &sdl->square_monster.pos);
      user = user->next;
      }
}
