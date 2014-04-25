/*
** port.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a/src_server/args
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Mar 24 10:42:22 2010 matias1 hastaran
** Last update Fri Apr 16 17:16:04 2010 thomas1 salomon
*/

#include "lmy_printf.h"
#include "lstr.h"
#include "lmy.h"
#include "args.h"
#include "server.h"

/*
** Set or get the server port
** set if fd == -1
*/
int		sog_server_port(int fd)
{
  static int	fd_s;

  if (fd != -1)
    fd_s = fd;
  return (fd_s);
}

int		find_port(int argc, char **argv)
{
  int		pos;
  int		port;

  pos = find_pos(argc, argv, "-p");
  if (pos == 0 || pos == -1)
    {
      my_printf("Not port or option already specified\n");
      return (0);
    }
  if (!my_str_isnum(argv[pos]))
    {
      my_printf("Port has to be a number\n");
      return (0);
    }
  port = sog_server_port(my_atoi(argv[pos]));
  if ((port > 65535) || (port <= 1024))
    {
      my_printf("The specified port is not valid\n");
      return (0);
    }
  return (port);
}
