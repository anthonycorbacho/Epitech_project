/*
** user.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Thu Apr  8 16:36:51 2010 matias1 hastaran
** Last update Thu Apr 22 14:58:24 2010 anthony1 corbacho
*/

#include <stdlib.h>
#include "lmy.h"
#include "lstr.h"
#include "lxsys.h"
#include "str_utils.h"

#include "SDL.h"

#include "pin.h"
#include "definitions.h"
#include "map.h"
#include "user.h"
#include "structure_server.h"

int		ppo(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_user	*save;

  save = elem->user;
  info = my_str_sep(del_bn(str), " ");
  while (elem->user->num != my_atoi(info[1] + 1))
    elem->user = elem->user->next;
  elem->user->x = my_atoi(info[2]);
  elem->user->y = my_atoi(info[3]);
  elem->user->direction = my_atoi(info[4]);
  elem->user->inca = 0;
  elem->user = save;
  send_pin(info[1] + 1, elem->socket);
  free(info);
  return (1);
}

int		plv(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_user	*save;

  save = elem->user;
  info = my_str_sep(del_bn(str), " ");
  while (elem->user->num != my_atoi(info[1] + 1))
    elem->user = elem->user->next;
  elem->user->level = my_atoi(info[2]);
  elem->user = save;
  free(info);
  return (1);
}

int		add_lvl_and_start_inc(int who, t_elem *elem)
{
  t_sdl_user	*save;

  save = elem->user;
  while (save)
    {
      if (save->num == who)
	save->inca = 1;
      save = save->next;
    }
  return (1);
}

int		pic(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  int		i;

  i = 4;
  info = my_str_sep(del_bn(str), " ");
  while (info[i])
    {
      add_lvl_and_start_inc(my_atoi(info[i] + 1), elem);
      i++;
    }
  send_pin(info[1] + 1, elem->socket);
  free(info);
  return (1);
}
