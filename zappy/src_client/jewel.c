/*
** jewel.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Thu Apr 15 18:01:38 2010 matias1 hastaran
** Last update Sun Apr 25 17:31:10 2010 thomas1 salomon
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
#include "level.h"
#include "check_cells_around.h"

void		take_jewel(t_player *p, char *name)
{
  char		*s;

  my_send(p->server_socket, "prend ");
  my_send(p->server_socket, name);
  my_send(p->server_socket, "\n");
  s = gnl_parsing(p);
  if (s && my_strcmp("ok\n", s) == 0)
    p->nbr++;
  free(s);
}

void		find_jewel(t_player *p, char *name)
{
  char		*s;

  my_printf("find jewel\n");
  take_food_if_exist(p);
  my_send(p->server_socket, "voir\n");
  s = gnl_parsing(p);
  if (s && pseudo_clever_move(s, name, p) == 1)
    take_jewel(p, name);
  free(s);
  if (p->nbr < p->final)
    {
      myopic_move(p);
      find_jewel(p, name);
    }
}

void		put_down_jewels(t_player *p)
{
  t_incantation incant[NB_INCANT] = INCANT_VALUES;
  int		i;
  int		nbr;
  char		*s;

  my_printf("put down jewel\n");
  i = -1;
  while (++i < NB_ROCKS)
    {
      if (incant[p->level - 1].rocks[i] > 0)
	{
	  nbr = incant[p->level - 1].rocks[i];
	  while (nbr > 0)
	    {
	      my_send(p->server_socket, "pose ");
	      my_send(p->server_socket, rocks_names[i]);
	      my_send(p->server_socket, "\n");
	      s = gnl_parsing(p);
	      my_printf("--->%s\n", s);
	      free(s);
	      nbr--;
	    }
	}
    }
}

void		check_jewel(t_player *p)
{
  t_incantation n[NB_INCANT] = INCANT_VALUES;
  int		i;
  char		*s;
  int		flag;

  flag = 1;
  my_printf("check jewel\n");
  my_send(p->server_socket, "inventaire\n");
  s = gnl_parsing(p);
  i = -1;
  if (s)
    while (++i < NB_ROCKS && flag)
      {
	if (check_inventaire(s, rocks_names[i], n[p->level - 1].rocks[i]) == 0)
	  {
	    p->jewel_flag = 1;
	    p->final = n[p->level - 1].rocks[i];
	    p->nbr = get_inventaire_nbr(s, rocks_names[i]);
	    p->jewel_name = rocks_names[i];
	    flag = 0;
	  }
      }
  if (flag == 1)
    p->level_flag = 1;
  free(s);
}
