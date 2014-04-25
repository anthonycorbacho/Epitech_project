/*
** request.h for request in /home/matt/work/my_zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sat Mar 20 21:42:22 2010 mathieu1 lornac
** Last update Tue Apr 13 10:41:59 2010 mathieu1 lornac
*/

#ifndef __REQUEST_H__
#define __REQUEST_H__

#include "llist.h"
#include "server.h"

/*
** Appends a request to the client list requests
*/
void		register_request(t_client *cl,
				 char *request);

/*
** Completely liberates a request structure
*/
void		free_request(t_request *req);

/*
** Mallocs a request structure
** duplicates the request string
*/
t_request	*malloc_request(char *r);

/*
** Free and remove the first request on the list
*/
void		remove_request(t_list **lst);

/*
** Determine reads size, reads ans analyses what has been read
*/
void		treat_request_next(t_client *cl, t_list **list_clients,
				   int read_s, int graphic);

/*
** Treats a client request
*/
void		treat_request(t_client *cl, t_list **list_clients, int graphic);

/*
** Treats a graphic request
*/
void		treat_graphic_request();

#endif /*__REQUEST_H__*/
