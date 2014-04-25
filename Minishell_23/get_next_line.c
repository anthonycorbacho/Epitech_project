#include <stdlib.h>
#include <unistd.h>

#include "lstr.h"
#include "lxsys.h"
#include "get_next_line.h"

char		*hasbnoz(char *in, char *out)
{
  while	(in < out)
    {
      if (*in == '\n' || *in == 0)
	return (in);
      ++in;
    }
  return (0);
}

void		prepare_buff(char *buffer, char **in , char **out)
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

char		*get_next_line(const int fd)
{
  static char	buffer[BUF_S];
  static char	*in = buffer;
  static char	*out = buffer;
  static int	n = 1;
  char		*ret;

  prepare_buff(buffer, &in, &out);
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
