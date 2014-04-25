/*
** xwrite.c for write X in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/xlib
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Mar  4 13:31:08 2010 anthony1 corbacho
** Last update Thu Mar  4 13:31:41 2010 anthony1 corbacho
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

ssize_t		xwrite(int d, void *buf, size_t nbytes)
{
  int		i;

  if ((i = write(d, buf, nbytes)) == -1)
    {
      write(2, "Impossible to write information\n", 32);
      exit(1);
    }
  return (nbytes);
}
