/*
** ip_connection.h for ip_connect in /home/math/Work/my_ftp
** 
** Made by math
** Login   <math@epitech.net>
** 
** Started on  Sun Feb 21 12:32:47 2010 math
** Last update Thu Mar  4 17:44:14 2010 mathieu1 lornac
*/

#ifndef __IP_CONNECTION__
#define __IP_CONNECTION__

/*
** Connection procedure for a server
** Returns the fd the server is listening to
*/
int			connect_server_ipc(int port, int max_client);

/*
** Connects a client to a server
** 1st param: client ip in char *
** 2nd param: server port
*/
int			connect_client_ipc(char * serv_ip, int serv_port);

/*
** Closes an ip connection
*/
void			close_connection_ipc(int fd);

#endif /*__IP_CONNECTION__*/
