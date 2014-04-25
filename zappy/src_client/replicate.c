/*
** replicate.c for repilcate in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** Started on  Fri Mar 19 17:32:11 2010 mathieu1 lornac
** Last update Sat Apr 24 16:36:09 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <sys/types.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "ip_connection.h"
#include "ip_protocol.h"

#include "definitions.h"
#include "commands.h"
#include "str_utils.h"
#include "map.h"
#include "replicate.h"
#include "position.h"
#include "gnl_parsing.h"

int			params_treatment(t_player *p)
{
  char			*s;

  my_send(p->server_socket, p->team_name);
  my_send(p->server_socket, "\n");
  s = gnl_parsing(p);
  if (!s)
    {
      my_printf("Bad team name\n");
      return (-1);
    }
  p->num_player = my_atoi(del_bn(s));
  free(s);
  return (0);
}

int			client_connection(t_player *p)
{
  char			*s;
  t_pos			*pos;

  pos = NULL;
  p->server_socket = connect_client_ipc(p->host_name, p->port);
  s = gnl_parsing(p);
  if (s)
    {
      if (my_strncmp(s, "BIENVENUE", 9) == 0)
	{
	  free(s);
	  if (params_treatment(p) == -1)
	    return (-1);
	  if ((s = gnl_parsing(p)))
	    {
	      pos = extract_coordinates_from_str(s);
	      my_printf("Map size X: %i Y: %i\n", pos->x, pos->y);
	    }
	  xfree_n(pos, s, (void *) -1);
	}
      return (1);
    }
  return (-1);
}
