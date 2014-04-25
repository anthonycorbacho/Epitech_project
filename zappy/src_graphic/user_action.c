/*
** user_action.c for list of user in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Apr 15 14:34:44 2010 anthony1 corbacho
** Last update Thu Apr 22 14:38:03 2010 anthony1 corbacho
*/

#include <stdlib.h>
#include "lmy.h"
#include "lstr.h"
#include "lxsys.h"
#include "str_utils.h"

#include "SDL.h"

#include "definitions.h"
#include "map.h"
#include "user.h"
#include "structure_server.h"

/*
** Delete user from a list of user
*/
void		free_first(t_sdl_user *to_del, t_elem *elem)
{
  to_del = elem->user;
  elem->user = elem->user->next;
  free(to_del);
}

int		pdi(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_user	*to_del;
  t_sdl_user	*save;

  SDL_mutexP(elem->mut_user);
  info = my_str_sep(del_bn(str), " ");
  if (elem->user->num == my_atoi(info[1] + 1))
    {
      to_del = NULL;
      free_first(to_del, elem);
      SDL_mutexV(elem->mut_user);
      return (1);
    }
  save = elem->user;
  while (elem->user->next->num != my_atoi(info[1] + 1))
    elem->user = elem->user->next;
  to_del = elem->user->next;
  if (elem->user->next->next != NULL)
    elem->user->next = elem->user->next->next;
  else
    elem->user->next = NULL;
  xfree_n(to_del, info, (void *)-1);
  elem->user = save;
  SDL_mutexV(elem->mut_user);
  return (1);
}

/*
** Set the end of incantation update de variable inca to 0
*/
int		pie(char *str, __attribute__((unused))t_elem *elem)
{
  t_sdl_user	*save;
  char		**info;

  save = elem->user;
  SDL_mutexP(elem->mut_user);
  info = my_str_sep(del_bn(str), " ");
  while (elem->user)
    {
      if (elem->user->x == my_atoi(info[1]) &&
	  elem->user->y == my_atoi(info[2]))
	elem->user->inca = 0;
      elem->user = elem->user->next;
    }
  free(info);
  elem->user = save;
  SDL_mutexV(elem->mut_user);
  return (1);
}

void		free_user_list(t_sdl_user *user)
{
  t_sdl_user	*save;

  save = user;
  while (user)
    {
      save = user->next;
      free(user);
      user = save;
    }
}
