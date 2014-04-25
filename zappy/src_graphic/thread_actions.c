/*
** thread_actions.c for action send by server in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Apr 13 19:05:26 2010 anthony1 corbacho
** Last update Tue Apr 20 16:22:24 2010 pierre1 rolland
*/

#include "SDL.h"
#include "SDL_thread.h"
#include "ip_protocol.h"
#include "lmy.h"
#include "lstr.h"
#include "lmy_printf.h"
#include "str_utils.h"
#include "lxsys.h"

#include "definitions.h"
#include "map.h"
#include "gnl_socket.h"
#include "thread_listen.h"
#include "define_graphic.h"
#include "user.h"

int		sgt(char *str, t_elem *elem)
{
  elem->actual_time_value = my_atoi(del_bn(str + 4));
  my_printf("Time : %d\n", elem->actual_time_value);
  return (1);
}

int		tna(char *str, __attribute__((unused))t_elem *elem)
{
  my_printf("Team name : %s\n", del_bn(str + 4));
  return (1);
}

int		msz(char *str, __attribute__((unused))t_elem *elem)
{
  int		x;
  int		y;
  char		**info;

  info = my_str_sep(str, " ");
  x = my_atoi(info[1]);
  y = my_atoi(del_bn(info[2]));
  map_size.x = x;
  map_size.y = y;
  initialize_map(x, y);
  free(info);
  return (1);
}

int		pbc(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_user	*save;

  save = elem->user;
  info = my_str_sep(del_bn(str), " ");
  while (elem->user->num != my_atoi(info[1] + 1))
    elem->user = elem->user->next;
  elem->user->bcast = 1;
  elem->user = save;
  free(info);
  return (1);
}

int		bct(char *str, __attribute__((unused))t_elem *elem)
{
  int		x;
  int		y;
  char		**info;
  int		i;

  i = -1;
  info = my_str_sep(del_bn(str), " ");
  x = my_atoi(info[1]);
  y = my_atoi(info[2]);
  fill_cell(x, y, info);
  free(info);
  return (1);
}
