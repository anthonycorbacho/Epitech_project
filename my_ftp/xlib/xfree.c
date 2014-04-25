/*
** xfree.c for free x in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/xlib
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Mar  4 13:25:07 2010 anthony1 corbacho
** Last update Thu Mar  4 13:25:37 2010 anthony1 corbacho
*/

#include		<stdlib.h>
#include		"lib_control.h"

void			xfree(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}
