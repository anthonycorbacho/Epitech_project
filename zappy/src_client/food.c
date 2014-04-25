/*
** food.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Thu Apr 15 15:34:01 2010 matias1 hastaran
** Last update Sun Apr 25 17:28:30 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "ip_protocol.h"
#include "ip_connection.h"
#include "gnl_parsing.h"
#include "client_movement.h"
#include "check_case.h"
#include "food.h"
#include "jewel.h"
#include "check_cells_around.h"
#include "get_players_case.h"

void		take_food_if_exist(t_player *p)
{
  char		*s;

  my_send(p->server_socket, "voir\n");
  if ((s = gnl_parsing(p)) && check_case(s, "nourriture", 0) == 1)
    {
      free(s);
      my_send(p->server_socket, "prend nourriture\n");
      s = gnl_parsing(p);
    }
  free(s);
}

int		search_next(t_player *p)
{
  char		*s;

  my_send(p->server_socket, "inventaire\n");
  if ((s = gnl_parsing(p)) && check_inventaire(s, "nourriture", 4) == 1)
    {
      free(s);
      return (1);
    }
  return (0);
}

int		search_food(t_player *p)
{
  char		*s;

  my_send(p->server_socket, "voir\n");
  s = gnl_parsing(p);
  if (s)
    {
      if (pseudo_clever_move(s, "nourriture", p) == 1)
	{
	  free(s);
	  my_send(p->server_socket, "prend nourriture\n");
	  if ((s = gnl_parsing(p)) && my_strcmp(s, "ok\n") == 0)
	    {
	      free(s);
	      if (search_next(p) == 1)
		return (1);
	    }
	}
    }
  free(s);
  myopic_move(p);
  search_food(p);
  return (1);
}

void		check_food(t_player *p)
{
  char		*s;

  my_send(p->server_socket, "inventaire\n");
  if ((s = gnl_parsing(p)))
    {
      my_printf("%s\n", s);
      if (check_inventaire(s, "nourriture", 4) == 0)
	p->food_flag = 1;
      free(s);
    }
  else
    free(s);
}
