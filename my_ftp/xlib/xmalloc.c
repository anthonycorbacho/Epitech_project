/*
** xmalloc.c for xmalloc ! in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/xlib
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Mar  4 13:26:14 2010 anthony1 corbacho
** Last update Thu Mar  4 13:43:38 2010 anthony1 corbacho
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib_control.h"

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      write(2, "Impossible to allocate Memory\n", 30);
      exit(0);
    }
  return (ptr);
}
