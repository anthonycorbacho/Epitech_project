/*
** process_clients.h for process_clients in /home/matt/work/my_ftp/src_server
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Feb 19 15:56:37 2010 mathieu1 lornac
** Last update Wed Apr  7 17:58:49 2010 damien1 coppel
*/

#ifndef	__PROCESS_CLIENTS__
#define __PROCESS_CLIENTS__

/*
** Accepts new connection and treats all the requests
*/
int			process_clients(int server_port);

/*
** On the first talk it initializes the client and returns 1
** Returns 0 if the client is uninitialized
** Returns 2 if too many clients in the team
*/
int		first_talk(t_list **list_clients, t_client *cl, char *request);

#endif
