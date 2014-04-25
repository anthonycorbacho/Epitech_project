/*
** request_receive.c for request receive in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Tue Apr  6 17:32:56 2010 mathieu1 lornac
** Last update Sun Apr 25 18:07:13 2010 damien1 coppel
*/

#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "ip_protocol.h"
#include "server.h"
#include "position.h"
#include "process_clients.h"
#include "str_utils.h"
#include "map.h"
#include "request.h"
#include "client_management.h"
#include "team_management.h"
#include "time_management.h"
#include "life_management.h"
#include "action.h"
#include "action_gr.h"

/*
** Returns a copy of the string contained between th pointers in and out
*/
char		*extract_string_from_buffer(t_client *cl)
{
  char		*ret;
  int		len;

  if (cl->in < cl->out)
    {
      ret = xmalloc(sizeof(*ret) * ((cl->out - cl->in) + 2));
      my_strncpy(ret, cl->in, cl->out - cl->in - 1);
      ret[cl->out - cl->in - 1] = 0;
    }
  else
    {
      len = cl->request + BUFFER_SIZE - cl->in;
      len += cl->out - cl->request;
      ret = xmalloc(sizeof(*ret) * (len + 2));
      my_strncpy(ret, cl->in, cl->request + BUFFER_SIZE - cl->in - 1);
      ret[cl->request + BUFFER_SIZE - cl->in - 1] = 0;
      my_strncat(ret, cl->request, cl->out - cl->request - 1);
      ret[len - 1] = 0;
    }
  return (ret);
}

/*
** Checks if a command has been received
** If so registers it to the request list
*/
void		analyse_income(t_list **list_clients, t_client *cl, int r)
{
  char		*cur;
  char		*str;

  cur = cl->out - r;
  while (cur < cl->out)
    {
      if (*cur == '\n')
	{
	  str = extract_string_from_buffer(cl);
	  my_printf("recu : %s\n", str);
	  if (!cl->team_name)
	    {
	      cl->in = cur + 1;
	      if (first_talk(list_clients, cl, str) > 1)
		break;
	    }
	  else
	    register_request(cl, str);
	  cl->in = cur + 1;
	  free(str);
	}
      cur++;
    }
}

/*
** Determine reads size, reads ans analyses what has been read
*/
void		treat_request_next(t_client *cl, t_list **list_clients,
				   int read_s, int graphic)
{
  int		r;

  r = read(cl->socket, cl->out, read_s);
  if (!r || r == -1)
    {
      if (!graphic)
	{
	  send_to_graph(player_dies_gr(cl));
	  remove_client(list_clients, cl, 1);
	}
      else
	{
	  my_printf("Graphic client has been removed\n");
	  free_client(cl);
	  vars->graphic_client = NULL;
	}
    }
  else
    {
      cl->out = cl->out + r;
      analyse_income(list_clients, cl, r);
      if (cl->out == cl->request + BUFFER_SIZE - 1)
	cl->out = cl->request;
      *(cl->out) = 0;
    }
}

/*
** Returns the space available in the buffer
*/
int		get_read_size(t_client *cl)
{
  int		space_left;

  if (cl->in <= cl->out)
    {
      space_left = cl->request + BUFFER_SIZE - cl->out;
      space_left += cl->in - cl->request;
    }
  else
    space_left = cl->in - cl->out;
  return (space_left);
}

/*
** Treats a client request
*/
void		treat_request(t_client *cl, t_list **list_clients, int graphic)
{
  int		read_s;

  if ((read_s = get_read_size(cl)) > CLIENT_READ_SIZE)
    read_s = CLIENT_READ_SIZE;
  if (!read_s)
    {
      cl->in = cl->request;
      cl->out = cl->request;
      cl->out = 0;
    }
  else
    {
      if (cl->request + BUFFER_SIZE - cl->out - 1 < read_s)
	read_s = cl->request + BUFFER_SIZE - cl->out - 1;
      treat_request_next(cl, list_clients, read_s, graphic);
    }
}
