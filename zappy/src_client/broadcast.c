/*
** broadcast.c for zappy client in /home/tom/zappy_2012s_coppel_a
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** 
** Started on  Tue Apr 20 18:34:15 2010 thomas1 salomon
** Last update Sun Apr 25 17:26:24 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"
#include "str_utils.h"

#include "definitions.h"
#include "ip_protocol.h"
#include "ip_connection.h"
#include "gnl_socket.h"
#include "check_case.h"
#include "jewel.h"
#include "food.h"
#include "gnl_parsing.h"
#include "client.h"

void			broadcast_for_level(t_player *p, char *s)
{
  char			**str;
  char			*id;

  str = my_str_sep(s, ",");
  str = my_str_sep(str[1], " ");
  if (my_atoi(str[2]) == 400 + p->level)
    {
      id = my_sprintf(p->id);
      p->target_id = my_atoi(str[3]);
      my_send(p->server_socket, "broadcast ");
      my_send(p->server_socket, str[2]);
      my_send(p->server_socket, " ");
      my_send(p->server_socket, id);
      my_send(p->server_socket, "\n");
      free(id);
      free(str);
      s = gnl_parsing(p);
      str = my_str_sep(s, ",");
      str = my_str_sep(str[1], " ");
      if (my_strcmp(str[2], "ko\n"))
	p->target_id = 0;
      free(s);
    }
  free(str);
}

void			broadcast_for_move(t_player *p, char *s)
{
  char			**str;

  str = my_str_sep(s, ",");
  str = my_str_sep(str[0], " ");
  p->move_flag = my_atoi(str[1]);
  free(str);
}

void			broadcast(t_player *p, char *s)
{
  char			*id;

  id = my_sprintf(p->id);
  if (my_strncmp(s + 8, "40", 10) == 0)
    broadcast_for_level(p, s);
  else if (my_strncmp(s + 0, id, my_strlen(id)) == 0)
    broadcast_for_move(p, s);
  free(id);
}

void			check_states(t_player *p)
{
  char			*s;

  my_printf("start check_states\n");
  p->food_flag = 0;
  p->jewel_flag = 0;
  check_food(p);
  check_jewel(p);
  my_send(p->server_socket, "inventaire\n");
  s = gnl_parsing(p);
  if (get_inventaire_nbr(s, "nourriture") == 10)
    {
      free(s);
      my_send(p->server_socket, "broadcast lol\n");
      s = gnl_parsing(p);
      my_send(p->server_socket, "fork\n");
      s = gnl_parsing(p);
    }
  free(s);
  my_printf("end check_states\n");
}

void			send_broadcast(t_player *p)
{
  char			*id;

  id = my_sprintf(p->target_id);
  my_send(p->server_socket, "broadcast ");
  my_send(p->server_socket, id);
  free(id);
  my_send(p->server_socket, " ");
  id = my_sprintf(p->target_id);
  my_send(p->server_socket, id);
  free(id);
  my_send(p->server_socket, "\n");
}
