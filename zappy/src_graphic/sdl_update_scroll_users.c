/*
** sdl_update_scroll_users.c for scroll in /home/pierre/Epitech/Projects/Zappy/
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Sat Apr 17 17:54:02 2010 pierre1 rolland
** Last update Tue Apr 20 16:21:27 2010 pierre1 rolland
*/

#include		"sdl_structure.h"
#include		"sdl_monsters_case.h"

void			event_scroll_user_down(t_sdl *sdl)
{
  get_number_monster_on_cell(sdl, sdl->mousex, sdl->mousey, 0);
  (sdl->scroll_users.scrollY)++;
  if (sdl->scroll_users.scrollY > sdl->scroll_users.scrollYmax)
    (sdl->scroll_users.scrollY)--;
}

void			event_scroll_user_up(t_sdl *sdl)
{
  get_number_monster_on_cell(sdl, sdl->mousex, sdl->mousey, 0);
  (sdl->scroll_users.scrollY)--;
  if (sdl->scroll_users.scrollY < 0)
    (sdl->scroll_users.scrollY)++;
}
