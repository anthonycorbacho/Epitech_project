/*
** client_incantation.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Tue Apr 20 11:40:52 2010 matias1 hastaran
** Last update Sun Apr 25 16:52:45 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "ip_protocol.h"
#include "ip_connection.h"
#include "gnl_socket.h"
#include "client.h"
#include "jewel.h"
#include "check_case.h"
#include "gnl_parsing.h"
#include "case_is_empty.h"

int			do_incantation(t_player *p)
{
  char			*s;

  put_down_jewels(p);
  my_send(p->server_socket, "incantation\n");
  s = gnl_parsing(p);
  my_printf("%s\n", s);
  if (my_strcmp(s, "ko\n") == 0)
    {
      free(s);
      return (1);
    }
  free(s);
  s = gnl_parsing(p);
  if (my_strncmp(s, "niveau ", 7) == 0)
    p->level++;
  free(s);
  return (1);
}

int			incantation(t_player *p)
{
  char			*s;

  my_printf("incantation\n");
  my_send(p->server_socket, "inventaire\n");
  s = gnl_parsing(p);
  if (check_inventaire(s, "nourriture", 4) == 0)
    {
      free(s);
      return (-1);
    }
  free(s);
  my_send(p->server_socket, "voir\n");
  s = gnl_parsing(p);
  if (case_is_empty(s) == 0)
    empty_case(p);
  free(s);
  p->send_flag = 1;
  if (p->level != 2)
    p->do_incant = 1;
  return (1);
}
