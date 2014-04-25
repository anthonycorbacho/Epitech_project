/*
** movement.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Thu Apr 15 15:35:30 2010 matias1 hastaran
** Last update Sat Apr 24 15:48:49 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "ip_protocol.h"
#include "ip_connection.h"
#include "gnl_socket.h"
#include "client_movement.h"
#include "gnl_parsing.h"

int		move(t_player *p, char *direction)
{
  char		*s;

  my_printf("move %s\n", direction);
  my_send(p->server_socket, direction);
  s = gnl_parsing(p);
  if (s && my_strcmp("ko\n", s) == 0)
    {
      free(s);
      return (-1);
    }
  free(s);
  return (1);
}

int		myopic_move(t_player *p)
{
  int		dir;

  my_printf("myopic move\n");
  dir = rand() % (4 - 1) + 1;
  if (dir == 1)
    {
      move(p, "droite\n");
      return (move(p, "avance\n"));
    }
  else if (dir == 2)
    return (move(p, "avance\n"));
  else
    {
      move(p, "gauche\n");
      return (move(p, "avance\n"));
    }
  return (-1);
}
