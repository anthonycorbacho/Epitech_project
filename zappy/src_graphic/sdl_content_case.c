/*
** sdl_content_case.c for sdl_content_case in /home/pierre/Epitech/Projects/
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Tue Apr 13 02:46:36 2010 pierre1 rolland
** Last update Tue Apr 20 16:16:56 2010 pierre1 rolland
*/

#include		"sdl_structure.h"
#include		"sdl_function.h"
#include		"sdl_function_next.h"

#include		"structure_server.h"
#include		"put_menu_items.h"

#include		"lmy_printf.h"
#include		"lstr.h"

t_map_elt		*get_cell_from_mouse(t_sdl *sdl, int xmouse,
					     int ymouse)
{
  t_map_elt		*elt;

  elt = NULL;
  if (ymouse >= 192 && xmouse <= map_size.x * 64 &&
      ymouse - 192 <= map_size.y * 64)
    return (get_cell(xmouse / 64 + sdl->scrollX,
		     (ymouse - 192) / 64 + sdl->scrollY));
  return (NULL);
}

void			put_text(char *text, int x, int y, t_sdl *sdl)
{
    SDL_Surface		*text_surf;
  SDL_Rect		pos;
  SDL_Color		black;
  TTF_Font		*font;

  if (!(font = TTF_OpenFont("src_graphic/font/slapstick.ttf", 20)))
    {
      my_printf("Error opening font\n");
      exit(0);
    }
  pos.x = x;
  pos.y = y;
  black.r = 0;
  black.g = 0;
  black.b = 0;
  text_surf = TTF_RenderText_Blended(font, text, black);
  SDL_BlitSurface(text_surf, NULL, sdl->screen, &pos);
  SDL_FreeSurface(text_surf);
  TTF_CloseFont(font);
}

int			put_text_egg(t_sdl *sdl)
{
  int			nb_egg;
  t_sdl_egg		*egg;

  nb_egg = 0;
  egg = sdl->elem->egg;
  while (egg)
    {
      if (egg->x == sdl->mousex &&
	  egg->y == sdl->mousey)
	{
	  nb_egg++;
	}
      egg = egg->next;
    }
  return (nb_egg);
}

void			get_items_cell(t_sdl *sdl, t_map_elt *elt)
{
  char			*info_cell;

  info_cell = my_sprintf(elt->food);
  put_text(info_cell, 93, 42, sdl);
  info_cell = my_sprintf(elt->rocks[0]);
  put_text(info_cell, 93, 85, sdl);
  info_cell = my_sprintf(elt->rocks[1]);
  put_text(info_cell, 93, 134, sdl);
  info_cell = my_sprintf(elt->rocks[2]);
  put_text(info_cell, 192, 42, sdl);
  info_cell = my_sprintf(elt->rocks[3]);
  put_text(info_cell, 192, 85, sdl);
  info_cell = my_sprintf(elt->rocks[4]);
  put_text(info_cell, 192, 134, sdl);
  info_cell = my_sprintf(elt->rocks[5]);
  put_text(info_cell, 291, 85, sdl);
  info_cell = my_sprintf(put_text_egg(sdl));
  put_text(info_cell, 291, 134, sdl);
  free(info_cell);
}

/*
** Put on the header the general informations about the items in the cell
*/
void			event_content_case(t_sdl *sdl, int mousex, int mousey)
{
  t_map_elt		*elt;

  put_menu_items_sdl(sdl);
  if ((elt = get_cell_from_mouse(sdl, mousex, mousey)) != NULL)
    {
      sdl->mousex = mousex / 64 + sdl->scrollX;
      sdl->mousey = (mousey - 192) / 64 + sdl->scrollY;
      get_items_cell(sdl, elt);
    }
}
