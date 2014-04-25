/*
** thread_pin.c for thread pin in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Apr 19 17:41:37 2010 anthony1 corbacho
** Last update Thu Apr 22 15:04:13 2010 anthony1 corbacho
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
#include "define_graphic.h"
#include "gnl_socket.h"
#include "user.h"
#include "structure_server.h"
#include "thread_listen.h"

void		add_defaut(t_sdl_user *user)
{
  user->inventaire.rocks[0] = 0;
  user->inventaire.rocks[1] = 0;
  user->inventaire.rocks[2] = 0;
  user->inventaire.rocks[3] = 0;
  user->inventaire.rocks[4] = 0;
  user->inventaire.rocks[5] = 0;
}

int		add_to_struct(t_sdl_user *user, char **info)
{
  int		cpt;
  int		i;

  cpt = 0;
  i = 0;
  user->inventaire.food = my_atoi(info[4]);
  while (info[cpt])
    cpt++;
  if (cpt < 11)
    {
      my_printf("Error on cmd pin\n");
      add_defaut(user);
      return (0);
    }
  cpt = 5;
  while (cpt < 11)
    {
      user->inventaire.rocks[i] = my_atoi(info[cpt]);
      cpt++;
      i++;
    }
  return (1);
}

int		pin(char *str, t_elem *elem)
{
  char		**info;
  t_sdl_user	*save;

  save = elem->user;
  info = my_str_sep(del_bn(str), " ");
  while (elem->user)
    {
      if (elem->user->num == my_atoi(info[1] + 1))
	{
	  add_to_struct(elem->user, info);
	  elem->user = save;
	  free(info);
	  return (1);
	}
      elem->user = elem->user->next;
    }
  elem->user = save;
  free(info);
  return (1);
}
