/*
** get_next_line.c for getnext in /home/lornac_a/getnextline
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Mon Nov  2 09:23:35 2009 mathieu1 lornac
** Last update Sun Apr 25 17:41:19 2010 mathieu1 lornac
*/

#include <stdlib.h>
#include <unistd.h>

#include "lstr.h"
#include "lxsys.h"
#include "ip_protocol.h"
#include "get_next_line.h"

void		prepare_buff_tl(char *buffer, char **in , char **out)
{
  int		i;

  i = 0;
  while (*in < *out)
    {
      buffer[i++] = **in;
      ++(*in);
    }
  *out = buffer + i;
  *in = buffer;
}

char		*get_next_line_tl(const int fd)
{
  static char	buffer[BUF_S];
  static char	*in = buffer;
  static char	*out = buffer;
  static int	n = 1;
  char		*ret;

  prepare_buff_tl(buffer, &in, &out);
  while (n && n != -1 && !hasbnoz(in, out) && (buffer + BUF_S - out) >= READ_S)
    {
      n = read(fd, out, READ_S);
      out += n;
    }
  if (n != -1 || (out - in) != 0)
    {
      in = (hasbnoz(in, out) == 0) ? (out) : (hasbnoz(in, out));
      ret = xmalloc(sizeof(*ret) * (in - buffer + 1));
      my_strncpy(ret, buffer, in - buffer);
      ret[in - buffer] = 0;
      if (*in == '\n')
	++in;
      if (n == 0)
	n = -1;
      return (ret);
    }
  return (0);
}
