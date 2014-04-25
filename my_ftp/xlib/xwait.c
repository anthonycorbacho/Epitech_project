/*
** xwait.c for xwait in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/xlib
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Mar  4 13:28:09 2010 anthony1 corbacho
** Last update Thu Mar  4 13:30:39 2010 anthony1 corbacho
*/

#include		<sys/types.h>
#include		<sys/wait.h>
#include		"lib_control.h"

pid_t			xwait(int *pid)
{
  pid_t			new_pid;

  if ((new_pid = wait(pid)) == -1)
    {
      write(2, "wait failled\n", 13);
      return (-1);
    }
  return (new_pid);
}
