/*
** send_to.c for send to clients in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Wed Apr  7 17:02:56 2010 mathieu1 lornac
** Last update Sun Apr 25 19:55:58 2010 mathieu1 lornac
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

void		remove_cl(t_list **list_clients, t_client *cl)
{
  my_printf("removing client\n");
  if (list_clients)
    remove_client(list_clients, cl, 1);
  else
    {
      free_client(cl);
      vars->graphic_client = NULL;
    }
}

/*
** Send a part of a command to a client
*/
void		send_a_piece(t_list **list_clients, t_client *cl)
{
  int		len;
  int		written;

  if (cl->to_send && (my_strlen(cl->to_send) != cl->to_send_len))
    {
      my_printf("Calcul len error\n");
      exit(1);
    }
  if (cl->to_send_len - cl->already_sent >= CLIENT_SEND_SIZE)
    len = CLIENT_SEND_SIZE;
  else
    len = cl->to_send_len - cl->already_sent;
  written = send(cl->socket, cl->to_send + cl->already_sent, len, 0);
  if (!written || (written == -1))
    remove_cl(list_clients, cl);
  else
    {
      cl->already_sent += written;
      if (cl->already_sent == cl->to_send_len)
	{
	  free(cl->to_send);
	  cl->to_send = NULL;
	  cl->to_send_len = 0;
	  cl->already_sent = 0;
	}
    }
}

/*
** Send a part of a command to the clients
*/
void		send_to_clients(t_list **list_clients)
{
  t_list	*cur;
  t_client	*cl;

  cur = *list_clients;
  while (cur)
    {
      cl = cur->data;
      if (cl->to_send)
	send_a_piece(list_clients, cl);
      cur = cur->next;
    }
  if (vars->graphic_client && vars->graphic_client->to_send)
    send_a_piece(NULL, vars->graphic_client);
}
