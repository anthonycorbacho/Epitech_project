/*
** my_login_tty.c for login_tty in /home/corbac_b/My Dropbox/epitech/C/my_script/FreeBSD
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 10 10:04:51 2010 anthony1 corbacho
** Last update Wed Feb 10 14:03:08 2010 anthony1 corbacho
*/

#include	"header_script.h"

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
      dup2(fd, 0);
      dup2(fd, 1);
      dup2(fd, 2);
      if (fd > 2)
        close(fd);
      return (0);
    }
  return (-1);
}
