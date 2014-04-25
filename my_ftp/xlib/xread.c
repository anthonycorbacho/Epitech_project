
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "xlib.h"

ssize_t		xread(int d, void *buf, size_t nbytes)
{
  int		ret;

  ret = read(d, buf, nbytes);
  if (ret == -1)
    {
      xwrite(2, "Could not read\n", 17);
      exit(1);
    }
  return (ret);
}
