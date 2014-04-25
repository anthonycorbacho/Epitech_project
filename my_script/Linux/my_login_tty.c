/*
** my_login_tty.c for login_tty in /home/corbac_b/My Dropbox/epitech/C/my_script/FreeBSD
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 10 10:04:51 2010 anthony1 corbacho
** Last update Mon Feb 15 14:24:09 2010 anthony1 corbacho
*/

#define _XOPEN_SOURCE 600
#include		<stdlib.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<stdio.h>
#define __USE_BSD
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<termios.h>
#include		<features.h>
#include		<pty.h>
#include		<sys/select.h>
#include		"header_script.h"

/*
** TIOCSCTTY: Make the calling controlling termimal
** for the process who calling it...
*/
int		my_login_tty(int fd)
{
  if (setsid() != -1)
    {
      if (ioctl(fd, TIOCSCTTY, (char *) 1) == -1)
        return (-1);
      if (dup2(fd, 0) == -1)
	my_erno(3,"Dup 0 error\n");
      if (dup2(fd, 1) == -1)
	my_erno(3, "Dup 1 error\n");
      if (dup2(fd, 2) == -1)
	my_erno(3, "Dup 3 error\n");
      return (0);
    }
  return (-1);
}
