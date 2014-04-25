/*
** player_management.c for player in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 19:46:02 2010 mathieu1 lornac
** Last update Sun Apr 25 17:31:37 2010 thomas1 salomon
*/

#include <sys/types.h>

#include "lxsys.h"

#include "definitions.h"
#include "client.h"

/*
** Mallocs and initialize a player
*/
t_player	*malloc_player()
{
  t_player	*p;

  p = xmalloc(sizeof(*p));
  return (p);
}

/*
** Liberates a player
*/
void		free_player(t_player *p)
{
  free(p);;
}
