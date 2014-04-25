/*
** movement.h for movement.h in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Apr  8 13:30:08 2010 anthony1 corbacho
** Last update Mon Apr 19 17:04:04 2010 pierre1 rolland
*/

#ifndef __MOVEMENT_H__
#define __MOVEMENT_H__

#include "sdl_movement.h"
#include "sdl_update_scroll_users.h"
#include "sdl_event_time.h"

typedef			void(*fct)();

typedef struct		s_mfunc
{
  SDLKey		sdlk_key;
  void			(*f)(t_sdl *sdl);
}			t_mfunc;

t_mfunc			list_key[9] = {
  {SDLK_UP, event_up},
  {SDLK_DOWN, event_down},
  {SDLK_LEFT, event_left},
  {SDLK_RIGHT, event_right},
  {SDLK_PAGEUP, event_scroll_user_up},
  {SDLK_PAGEDOWN, event_scroll_user_down},
  {SDLK_d, event_time_up},
  {SDLK_u, event_time_down},
  {0, 0}
};

#endif /*__MOVEMENT_H__*/
