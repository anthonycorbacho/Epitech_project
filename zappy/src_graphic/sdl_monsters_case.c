/*
** sdl_content_case.c for sdl_content_case in /home/pierre/Epitech/Projects/
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Tue Apr 13 02:46:36 2010 pierre1 rolland
** Last update Tue Apr 20 19:57:01 2010 pierre1 rolland
*/

#include		"sdl_structure.h"
#include		"user.h"

#include		"sdl_function.h"
#include		"sdl_function_next.h"

#include		"sdl_content_case.h"
#include		"sdl_put_updown.h"
#include		"put_menu_items.h"
#include		"put_menu_monster.h"

#include		"sdl_print_invent.h"
#include		"lstr.h"
#include		"pin.h"

#include		"xsdl.h"

int			get_number_monster_on_cell(t_sdl *sdl, 
						   int x, int y, int flg)
{
  t_sdl_user		*user_;
  int			nb;

  SDL_mutexP(sdl->elem->mut_user);
  user_ = sdl->elem->user;
  nb = 0;
  while (user_ != NULL)
    {
      if (user_->x == x && user_->y == y)
	nb++;
      user_ = user_->next;
    }
  if (flg)
    {
      if (nb > 3)
	sdl->scroll_users.scrollYmax = nb - 3;
      else
	sdl->scroll_users.scrollYmax = 0;
      sdl->scroll_users.scrollY = 0;
    }
  SDL_mutexV(sdl->elem->mut_user);
  return (nb);
}

void			put_minimonster(t_sdl *sdl, t_sdl_user *user, int y)
{
  SDL_Rect		rec;
  SDL_Rect		pos;

  rec.x = 27 * (user->direction - 1);
  rec.y = 27 * (user->level - 1);
  rec.w = 27;
  rec.h = 27;
  pos.x = 405;
  pos.y = 35 + 50 * y;
  xSDL_BlitSurface(sdl->minimonster.minimonster, &rec, sdl->screen, &pos);
}

void			treat_single_user(t_sdl_user *user_, t_sdl *sdl, int *i)
{
  if (user_->x == sdl->mousex && user_->y == sdl->mousey)
    {
      send_pin(my_sprintf(user_->num), sdl->elem->socket);
      put_minimonster(sdl, user_, *i);
      if (sdl->scroll_users.scrollY > 0)
	put_updown(sdl, 820, 55, 1);
      if (sdl->scroll_users.scrollY < sdl->scroll_users.scrollYmax)
	put_updown(sdl, 820, 115, 0);
      put_text(user_->team, 432, 40 + 50 * *i, sdl);
      print_inv_img(sdl, 40 + 50 * *i);
      print_inv_num(sdl, 40 + 50 * *i, user_);
      (*i)++;
    }
}

void			event_monsters_case(t_sdl *sdl, int mousex, int mousey)
{
  t_map_elt		*elt;
  t_sdl_user		*user_;
  int			i;

  put_menu_monsters_sdl(sdl);
  SDL_mutexP(sdl->elem->mut_user);
  user_ = sdl->elem->user;
  if ((elt = get_cell_from_mouse(sdl, mousex, mousey)) != NULL)
    {
      sdl->mousex = mousex / 64 + sdl->scrollX;
      sdl->mousey = (mousey - 192) / 64 + sdl->scrollY;
      i = 0;
      while (i < sdl->scroll_users.scrollY && user_ != NULL)
	{
	  user_ = user_->next;
	  i++;
	}
      i = 0;
      while (i < 3 && user_ != NULL)
	{
	  treat_single_user(user_, sdl, &i);
	  user_ = user_->next;
	}
    }
  SDL_mutexV(sdl->elem->mut_user);
}
