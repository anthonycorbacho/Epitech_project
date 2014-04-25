/*
** my_opentty.c for open tty in /home/corbac_b/My Dropbox/epitech/C/my_script/FreeBSD
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb  9 18:42:33 2010 anthony1 corbacho
** Last update Mon Feb 15 14:24:56 2010 anthony1 corbacho
*/

#define _XOPEN_SOURC 600
#define _GNU_SOURCE
#define __USE_BSD

#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/ioctl.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<termios.h>
#include	<features.h>
#include	<pty.h>
#include	<stropts.h>
#include	<sys/select.h>
#include	"header_script.h"

/*
** posix_openpt: Return the file descriptor pseudo-terminal
** ptsname: Get the path name like /dev/pty/XY
** tcseattr: Set the termios structure.
** ioctl: control device
*/
int		 my_openpty(int *amaster, int *aslave, char *name,
			    t_termios *term, t_winsize *winp)
{
  if ((*amaster = getpt()) == -1)
    my_erno(3, "TTY fail\n");
  if ((grantpt(*amaster)) == -1)
    my_erno(3, "Grantpt fail\n");
  if ((unlockpt(*amaster)) == -1)
    my_erno(3, "Unlock fail\n");
  if ((*aslave = open(ptsname(*amaster), O_RDWR, S_IRWXU)) == -1)
    my_erno(3, "Aslave Error\n");
  if (name != 0)
    name = ptsname(*amaster);
  if (term != 0)
    if (tcsetattr(*amaster - 3, TCSAFLUSH, term) == -1)
      my_erno(3, "Tcset Error\n");
  if (winp != 0)
    if (ioctl(*amaster, TIOCSWINSZ, winp) == -1)
      my_erno(3, "IOCTL Error\n");
  return (0);
}
