/*
** xfork.c for xforc in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/xlib
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Mar  4 13:23:56 2010 anthony1 corbacho
** Last update Thu Mar  4 13:24:49 2010 anthony1 corbacho
*/

#include		<sys/types.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"lib_control.h"

pid_t			xfork(void)
{
  pid_t	pid;

  pid = 0;
  if ((pid = fork()) == -1)
    {
      xwrite(2, "fork failed\n", 12);
      exit(0);
    }
  return (pid);
}
