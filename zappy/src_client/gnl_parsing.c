/*
** gnl_parsing.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Tue Apr 20 22:09:20 2010 matias1 hastaran
** Last update Sat Apr 24 16:01:39 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"

#include "definitions.h"
#include "ip_protocol.h"
#include "ip_connection.h"
#include "broadcast.h"
#include "gnl_socket.h"
#include "gnl_parsing.h"
#include "lxsys.h"

char			*gnl_parsing(t_player *p)
{
  char			*s;

  s = get_next_line_socket(p->server_socket);
  if (s && my_strncmp(s, "message ", 8) != 0)
    return (s);
  else if (!s || my_strcmp(s, "mort\n") == 0)
    {
      p->end_flag = 1;
      xfree_n(p->host_name, p->team_name, (void *)-1);
      close_connection_ipc(p->server_socket);
      free(p);
      my_printf("mort\n");
      exit(EXIT_SUCCESS);
    }
  if (s)
    {
      broadcast(p, s);
      s = gnl_parsing(p);
    }
  return (s);
}
