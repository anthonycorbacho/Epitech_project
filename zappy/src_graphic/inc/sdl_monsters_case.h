/*
** sdl_monsters_case.h for sdl_monsters_case in /home/pierre/Epitech/Projects/Zappy/zappy_2012s_coppel_a
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Sat Apr 17 18:34:36 2010 pierre1 rolland
** Last update Tue Apr 20 15:28:40 2010 pierre1 rolland
*/

#ifndef __SDL_MONSTERS_CASE_H__
#define __SDL_MONSTERS_CASE_H__

int                     get_number_monster_on_cell(t_sdl *sdl, int x, int y, int flag);
void                    event_monsters_case(t_sdl *sdl, int mousex, int mousey);

#endif /*__SDL_MONSTERS_CASE_H__*/
