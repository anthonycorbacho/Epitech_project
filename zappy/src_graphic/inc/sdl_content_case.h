/*
** sdl_content_case.h for contant contant in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Apr 13 15:31:15 2010 anthony1 corbacho
** Last update Sat Apr 17 18:41:44 2010 pierre1 rolland
*/

#ifndef __SDL_CONTENT_CASE_H__
#define __SDL_CONTENT_CASE_H__

void                    put_text(char *, int, int, t_sdl *);
void                    event_content_case(t_sdl *, int, int);
t_map_elt               *get_cell_from_mouse(t_sdl *sdl, int xmouse,
                                             int ymouse);

#endif /*__SDL_CONTENT_CASE_H__*/
