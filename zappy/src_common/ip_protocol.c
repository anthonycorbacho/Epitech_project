/*
** ip_protocol.c for ip protocol in /work/Dropbox/Epitech/Tek2/zappy_2012s_coppel_a/src_common
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Mon Mar 15 19:38:07 2010 mathieu1 lornac
** Last update Wed Apr 14 20:05:33 2010 damien1 coppel
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "ip_protocol.h"

/*
** Send len bytes to the specified socket
*/
int		my_ip_send(int socket, char *buf, int len)
{
  int		written;
  int		done;

  done = 0;
  while (done < len)
    {
      written = send(socket, buf + done, len - done, 0);
      if ((written == -1) || !written)
	return (1);
      else
	done += written;
    }
  return (0);
}

/*
** Checks if the string contains a \0 or a \n
*/
char		*hasbnoz(char *in, char *out)
{
  while	(in < out)
    {
      if (*in == '\n' || !*in)
	return (in);
      ++in;
    }
  return (0);
}

/*
** Receive len bytes from the specified socket
*/
int		my_ip_receive(int socket, char **buf, int len)
{
  int		written;
  char		*in;

  in = *buf;
  while (!hasbnoz(*buf, in))
    {
      written = recv(socket, in, len, 0);
      if ((written == -1) || !written || ((in - *buf) > MESS_MAX_SIZE))
	return (1);
      in += written;
    }
  *in = 0;
  return (0);
}

/*
** Sends the string to the specified fd
** returns 0 in succes
** 1 if an error occurs
*/
int		my_send(int fd, char *s)
{
  return (my_ip_send(fd, s, my_strlen(s)));
}

/*
** Reads fron the file descriptor
** Mallocs the necessary space
** returns (char *) -1 if an error occurs
*/
char		*my_receive(int fd)
{
  char		*buf;

  buf = xmalloc(sizeof(*buf) * MESS_MAX_SIZE);
  if (my_ip_receive(fd, &buf, MESS_MAX_SIZE))
    {
      xfree(buf);
      return ((char *) -1);
    }
  return (buf);
}
