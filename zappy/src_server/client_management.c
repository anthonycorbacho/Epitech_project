/*
** client_management.c for  in /home/matt/work/my_irc/my_irc
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sun Mar  7 13:59:24 2010 mathieu1 lornac
** Last update Thu Apr 22 14:47:35 2010 mathieu1 lornac
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "server.h"
#include "client_management.h"
#include "commands.h"
#include "ip_protocol.h"
#include "str_utils.h"
#include "map.h"
#include "life_management.h"
#include "request.h"

/*
** Liberates all the elements that has been malloced for a client
*/
void		free_client(t_client *c)
{
  t_list	*l_req;
  t_request	*req;

  if (close(c->socket) == -1)
    xwrite(1, FD_CLOSING_ERROR, my_strlen(FD_CLOSING_ERROR));
  free(c->team_name);
  free(c->to_send);
  l_req = c->requests;
  while (l_req)
    {
      req = l_req->data;
      free_request(req);
      l_req = l_req->next;
    }
  my_free_all_list_struct(c->requests);
  free(c);
}

/*
** Mallocs a new client and initializes it to the default values
*/
t_client	*malloc_client()
{
  t_client	*c;
  static int	id = 0;
  int		i;

  c = xmalloc(sizeof(*c));
  c->socket = -1;
  c->team_name = NULL;
  c->requests = NULL;
  c->orientation = 1;
  c->level = 1;
  c->id = id++;
  c->out = c->request;
  c->in = c->request;
  c->request[0] = 0;
  c->to_send = NULL;
  c->to_send_len = 0;
  c->already_sent = 0;
  i = -1;
  while (++i < NB_ROCKS)
    c->rocks[i] = 0;
  c->life = DEFAULT_LIFE;
  xgettimeofday(&(c->next_meal), 0);
  set_next_meal(&(c->next_meal));
  return (c);
}

/*
** Accepts a new connection and adds the new client to the client list
** Sends to the client the welcome message
*/
void			new_client_connection(t_list **client_list,
					      int server_fd)
{
  struct sockaddr	client_in;
  size_t		client_in_len;
  int			fd;
  t_client		*cl;

  client_in_len = sizeof(client_in);
  fd = accept(server_fd, (struct sockaddr *)&client_in, &client_in_len);
  my_printf("Client connected fd associated: %d\n", fd);
  cl = malloc_client();
  cl->socket = fd;
  my_put_elem_in_list(client_list, cl);
  cl->to_send = my_strdup(CMD_WELCOME);
  cl->to_send_len = my_strlen(CMD_WELCOME);
}

/*
** Client comparison for the list functions
*/
int		client_cmp(t_client *c1, t_client *c2)
{
  return (c1->socket != c2->socket);
}

/*
** Removes a client from the client list
** if to_free != 0, liberates the client struct
*/
void		remove_client(t_list **list_clients, t_client *cl, int to_free)
{
  t_client	*c;
  t_client	ref;

  my_printf("Client connected on socket %d has been removed\n", cl->socket);
  ref.socket = cl->socket;
  c = my_find_elm_eq_in_list(*list_clients, &ref, client_cmp);
  my_rm_all_eq_from_list(list_clients, &ref, client_cmp);
  if (to_free)
    free_client(c);
}
