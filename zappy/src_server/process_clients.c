/*
** process_clients.c for process_clients in /home/matt/work/my_irc/my_irc
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Thu Mar  4 17:58:23 2010 mathieu1 lornac
** Last update Mon Apr 19 15:55:10 2010 mathieu1 lornac
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
#include "egg_management.h"
#include "send_to.h"

/*
** Prepares the fd_set parameter for select
** returns the highest fd + 1
*/
int			prepare_fds(fd_set *fds, t_list *list_clients,
				    int server_fd)
{
  int			v_max;
  t_client		*cl;

  FD_ZERO(fds);
  FD_SET(server_fd, fds);
  v_max = server_fd;
  if (vars->graphic_client && v_max < vars->graphic_client->socket)
    v_max = vars->graphic_client->socket;
  if (vars->graphic_client)
    FD_SET(vars->graphic_client->socket, fds);
  while (list_clients)
    {
      cl = (t_client *)list_clients->data;
      FD_SET(cl->socket, fds);
      if (cl->socket > v_max)
	v_max = cl->socket;
      list_clients = list_clients->next;
    }
  return (v_max + 1);
}

/*
** Finds out which client is talking to the server and treats its request
*/
void			look_and_treat(fd_set *fds, t_list **list_clients,
				    __attribute__((unused)) int server_fd)
{
  t_client		*cl;
  t_list		*list;
  int			size_lst;

  cl = NULL;
  list = *list_clients;
  size_lst = my_list_size(list);
  if (vars->graphic_client && FD_ISSET(vars->graphic_client->socket, fds))
    treat_request(vars->graphic_client, NULL, 1);
  while (list)
    {
      cl = list->data;
      if (FD_ISSET(cl->socket, fds))
	treat_request(cl, list_clients, 0);
      if (my_list_size(*list_clients) != size_lst)
	break;
      list = list->next;
    }
}

/*
** Waits until there is some activity on one of the fds in the select
*/
int			process_clients(int server_fd)
{
  fd_set		fds;
  int			highest_fd;
  struct timeval	timeout;

  timeout.tv_sec = 0;
  while (1)
    {
      timeout.tv_usec = vars->latence;
      check_life();
      highest_fd = prepare_fds(&fds, vars->list_clients, server_fd);
      check_time_and_answer();
      check_on_eggs();
      if (select(highest_fd, &fds, NULL, NULL, &timeout) == -1)
	{
	  my_putstr_e("select_failed\n");
	  exit(1);
	}
      if (FD_ISSET(server_fd, &fds))
	new_client_connection(&vars->list_clients, server_fd);
      else
	look_and_treat(&fds, &vars->list_clients, server_fd);
      send_to_clients(&vars->list_clients);
    }
  return (0);
}
