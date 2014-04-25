/*
** request.c for request in /home/matt/work/my_zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sat Mar 20 21:32:59 2010 mathieu1 lornac
** Last update Thu Apr 22 14:42:48 2010 mathieu1 lornac
*/

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "server.h"
#include "request.h"

/*
** Completely liberates a request structure
*/
void		free_request(t_request *req)
{
  free(req->request);
  free(req);
}

/*
** Mallocs a request structure
** duplicates the request string
*/
t_request	*malloc_request(char *r)
{
  t_request	*req;

  req = xmalloc(sizeof(*req));
  req->request = my_strdup(r);
  req->end_time.tv_sec = 0;
  req->cmd = NULL;
  return (req);
}

/*
** Appends a request to the client list requests
*/
void		register_request(t_client *cl, char *str)
{
  t_list	*r;
  t_list	*new_l;
  t_request	*new_r;

  if (my_list_size(cl->requests) < MAX_REQUESTS_CLIENT)
    {
      my_printf("add req to client : %d\n", cl->socket);
      new_r = malloc_request(str);
      new_l = xmalloc(sizeof(*new_l));
      new_l->next = NULL;
      new_l->data = new_r;
      r = cl->requests;
      while (r && (r->next))
	r = r->next;
      if (!r)
	cl->requests = new_l;
      else
	r->next = new_l;
    }
  else
    my_printf("Client on socket %d request kicked\n", cl->socket);
}

/*
** Free and remove the first request on the list
*/
void		remove_request(t_list **lst)
{
  t_list	*to_rm;

  free_request((t_request*)(*lst)->data);
  to_rm = *lst;
  *lst = (*lst)->next;
  free(to_rm);
}
