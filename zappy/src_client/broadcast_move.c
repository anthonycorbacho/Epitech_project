/*
** broadcast_move.c for zappy client in /home/tom/zappy_2012s_coppel_a
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** 
** Started on  Tue Apr 20 10:57:21 2010 thomas1 salomon
** Last update Sun Apr 25 17:26:43 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"

#include "ip_protocol.h"
#include "ip_connection.h"
#include "gnl_socket.h"
#include "gnl_parsing.h"
#include "client.h"
#include "client_movement.h"
#include "broadcast_move.h"

int			move_to_7(t_player *p)
{
  if (move(p, "droite\n") == -1)
    return (0);
  return (1);
}

int			move_to_5(t_player *p)
{
  char			*s;

  my_send(p->server_socket, "gauche\ngauche\n");
  s = gnl_parsing(p);
  if (my_strncmp(s, "ko", 2) == 0)
    {
      free(s);
      return (0);
    }
  s = gnl_parsing(p);
  if (my_strncmp(s, "ko", 2) == 0)
    {
      free(s);
      return (0);
    }
  return (1);
}

int			move_to_3(t_player *p)
{
  if (move(p, "gauche\n") == -1)
    return (0);
  return (1);
}

int			move_on_direction(t_player *p)
{
  int			i;

  i = 1;
  if (p->move_flag == 3)
    {
      if (move_to_3(p) == 0)
	return (0);
    }
  else if (p->move_flag == 5)
    {
      if (move_to_5(p) == 0)
	return (0);
    }
  else if (p->move_flag == 7)
    {
      if (move_to_7(p) == 0)
	return (0);
    }
  if (move(p, "avance\n") == -1)
    i = 0;
  return (i);
}

int		      broadcast_move(t_player *p)
{
  if (p->move_flag == 0)
    return (2);
  if (p->move_flag % 2 != 0)
    return (move_on_direction(p));
  else
    {
      if (move(p, "avance\n") == -1)
	return (0);
    }
  return (1);
}
