/*
** ip_connection.c for zappy in /home/damien/work_local/zappy/src_common
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Fri Apr 16 13:05:24 2010 damien1 coppel
** Last update Fri Apr 16 13:05:51 2010 damien1 coppel
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "lstr.h"

#include "ip_connection.h"

/*
** Connection procedure for a server
** Returns the fd the server is listening to
*/
int			connect_server_ipc(int port, int max_client)
{
  struct sockaddr_in	sin;
  int			s;

  s = socket(PF_INET, SOCK_STREAM, 0);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)))
    {
      my_putstr_e("Bind unsuccessful\n");
      exit(2);
    }
  if (listen(s, max_client))
    {
      my_putstr_e("listen unsuccessful\n");
      exit(2);
    }
  return (s);
}

/*
** Connects a client to a server
** 1st param: client ip in char *
** 2nd param: server port
*/
int			connect_client_ipc(char * serv_ip, int serv_port)
{
  int			s;
  struct sockaddr_in	sin;

  s = socket(PF_INET, SOCK_STREAM, 0);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(serv_port);
  sin.sin_addr.s_addr = inet_addr(serv_ip);
  if (connect(s, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)))
    {
      my_putstr_e("Connection problem\n");
      exit(2);
    }
  return (s);
}

/*
** Closes an ip connection
*/
void			close_connection_ipc(int fd)
{
  close(fd);
}
