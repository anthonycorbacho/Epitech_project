/*
** main.c for my_telnet\ in /home/damien/work_local/zappy_2012s_coppel_a/my_telnet
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Fri Apr 16 16:44:26 2010 damien1 coppel
** Last update Sun Apr 25 17:48:01 2010 mathieu1 lornac
*/

#include "ip_connection.h"
#include "ip_protocol.h"
#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "str_utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

char		*get_next_line_tl(const int fd);

int		out = 0;

void		*listen_thread(void *v_fd)
{
  int		fd;
  char		*rc;

  fd = (int)v_fd;
  while (42)
    {
      rc = get_next_line_tl(fd);
      if (!rc)
	{
	  out = 1;
	  break;
	}
      my_printf("=> %s\n", rc);
      free (rc);
      usleep(10);
    }
  return (NULL);
}

void		read_thread(int fd)
{
  char		*rd;

  while (!out)
    {
      rd = get_next_line_tl(0);
      if (!rd)
	break;
      rd = dupcat(rd, my_strdup("\n"));
      if (*rd && *rd != '\n')
	my_send(fd, rd);
      free(rd);
      usleep(10);
    }
}

int		main(int ac, char **argv)
{
  int		fd;
  pthread_t	thread;

  if (ac != 2)
    {
      my_printf("usage : ./telnet port\n");
      return (0);
    }
  my_printf("my_telnet connection...");
  fd = connect_client_ipc("127.0.0.1", my_atoi(argv[1]));
  my_printf(" ok :)\n");
  pthread_create(&thread, NULL, listen_thread, (void *)fd);
  read_thread(fd);
  my_printf("Quitting telnet\n");
  return (0);
}
