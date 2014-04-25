/*
** xmalloc.c for xmalloc in /home/anthony/Dropbox/epitech/C/my_script
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 09:55:59 2010 anthony1 corbacho
** Last update Tue Mar  9 11:22:18 2010 anthony1 corbacho
*/

#include	<stdlib.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/uio.h>
#include	<unistd.h>

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == 0)
    {
      write(2, "Malloc fail\n", 12);
      exit(1);
    }
  return (ptr);
}

void		xfree(void *ptr)
{
  if (ptr != 0)
    free(ptr);
}

ssize_t		xwrite(int d, void *buffer, size_t buffer_len)
{
  int		fd;

  if ((fd = write(d, buffer, buffer_len)) == -1)
    {
      write(2, "Write error\n", 12);
      exit(1);
    }
  return (buffer_len);
}
