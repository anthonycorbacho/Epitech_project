/*
** my_opentty.c for open tty in /home/corbac_b/My Dropbox/epitech/C/my_script/FreeBSD
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb  9 18:42:33 2010 anthony1 corbacho
** Last update Thu Feb 11 00:08:46 2010 anthony1 corbacho
*/

#include	"header_script.h"

int		my_posix_openpt(int flag)
{
  char		*str;
  int		fd;

  str = my_strdup("/dev/ptyp0");
  while ((fd = open(str, flag)) < 0)
    {
      if (str[8] == 'z' && str[9] == 'f')
	{
	  free(str);
	  return (-1);
	}
      if (str[9] == 'f')
	{
	  str[8]++;
	  str[9] = 48;
	}
      if (str[9] == '9')
	str[9] += 53;
      str[9]++;
    }
  free(str);
  return (fd);
}

/*
** posix_openpt: Return the file descriptor pseudo-terminal
** ptsname: Get the path name like /dev/ptyXY
** tcseattr: Set the termios structure.
** ioctl: control device
*/
int		 my_openpty(int *amaster, int *aslave, char *name,
			    t_termios *term, t_winsize *winp)
{

  if ((*amaster = my_posix_openpt(O_RDWR)) == -1)
    my_erno(3, "TTY fail\n");
  if ((*aslave = open(ptsname(*amaster), O_RDWR)) == -1)
    my_erno(3, "Aslave error\n");
  if (name != 0)
    name = ptsname(*amaster);
  if (term != 0)
    tcsetattr(0, TCSAFLUSH, term);
  if (winp != 0)
    ioctl(*amaster, TIOCSWINSZ, winp);
  return (0);
}
