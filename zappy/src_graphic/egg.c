/*
** egg.c for function for eggs in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Apr 15 18:43:30 2010 anthony1 corbacho
** Last update Tue Apr 20 16:15:13 2010 pierre1 rolland
*/

#include "lmy.h"
#include "lstr.h"
#include "lmy_printf.h"
#include "str_utils.h"
#include "lxsys.h"

#include "SDL.h"

#include "definitions.h"
#include "map.h"
#include "define_graphic.h"
#include "user.h"
#include "structure_server.h"
#include "thread_listen.h"

int		enw(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_egg	*new;
  t_sdl_egg	*save;

  info = my_str_sep(del_bn(str), " ");
  save = elem->egg;
  new = xmalloc(sizeof(t_sdl_egg));
  new->num = my_atoi(info[1] + 1);
  new->x = my_atoi(info[3]);
  new->y = my_atoi(info[4]);
  new->status = 0;
  new->next = NULL;
  if (elem->egg == NULL)
    elem->egg = new;
  else
    {
      while (elem->egg->next != NULL)
	elem->egg = elem->egg->next;
      elem->egg->next = new;
      elem->egg = save;
    }
  free(info);
  return (1);
}

int		eht(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_egg	*save;

  info = my_str_sep(del_bn(str), " ");
  save = elem->egg;
  while (elem->egg)
    {
      if (elem->egg->num == my_atoi(info[1] + 1))
	elem->egg->status = 1;
      elem->egg = elem->egg->next;
    }
  free(info);
  elem->egg = save;
  return (1);
}

void		delete_first(t_elem *elem)
{
  t_sdl_egg	*to_del;

  to_del = elem->egg;
  elem->egg = elem->egg->next;
  free(to_del);
}

int		edi(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_egg	*to_del;
  t_sdl_egg	*save;

  SDL_mutexP(elem->mut_egg);
  info = my_str_sep(del_bn(str), " ");
  if (elem->egg->num == my_atoi(info[1] + 1))
    {
      delete_first(elem);
      SDL_mutexV(elem->mut_egg);
      return (1);
    }
  save = elem->egg;
  while (elem->egg->next->num != my_atoi(info[1] + 1))
    elem->egg = elem->egg->next;
  to_del = elem->egg->next;
  if (elem->egg->next->next != NULL)
    elem->egg->next = elem->egg->next->next;
  else
    elem->egg->next = NULL;
  xfree_n(to_del, info, (void *)-1);
  elem->egg = save;
  SDL_mutexV(elem->mut_egg);
  return (1);
}
