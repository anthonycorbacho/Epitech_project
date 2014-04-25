/*
** thread_pnw.c for function for pnw in /home/anthony/Zappy/
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Apr 19 19:02:30 2010 anthony1 corbacho
** Last update Tue Apr 20 16:23:09 2010 pierre1 rolland
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
#include "lmy_printf.h"

int		pnw_init(t_sdl_user *new, char **info, int so)
{
  int		cpt;

  cpt = 0;
  while (info[cpt])
    cpt++;
  if (cpt < 7)
    {
      my_printf("Error pnw invalid!\n");
      exit (0);
    }
  send_pin(info[1] + 1, so);
  new->num = my_atoi(info[1] + 1);
  new->level = my_atoi(info[5]);
  new->x = my_atoi(info[2]);
  new->y = my_atoi(info[3]);
  new->inca = 0;
  new->direction = my_atoi(info[4]);
  new->team = my_strdup(info[6]);
  new->next = NULL;
  return (1);
}

/*
** Add to the list of user a new user
*/
int		pnw(char *str, __attribute__((unused))t_elem *elem)
{
  char		**info;
  t_sdl_user	*new;
  t_sdl_user	*save;

  new = xmalloc(sizeof(t_sdl_user));
  info = my_str_sep(del_bn(str), " ");
  pnw_init(new, info, elem->socket);
  if (elem->user == NULL)
    elem->user = new;
  else
    {
      save = elem->user;
      while (elem->user->next != NULL)
        elem->user = elem->user->next;
      elem->user->next = new;
      elem->user = save;
    }
  free(info);
  return (1);
}
