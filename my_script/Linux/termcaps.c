/*
** termcaps.c for termcap in /home/corbac_b/My Dropbox/epitech/C/my_script
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb  9 14:08:35 2010 anthony1 corbacho
** Last update Mon Feb 15 13:52:31 2010 anthony1 corbacho
*/

#include		"header_script.h"

extern	t_script       	script;

void			init_termios(t_termios *termios)
{
  script.halt = 0;
  if (tcgetattr(0, termios) < 0)
    my_erno(3, "Tcgerattr fail\n");
  if (tcgetattr(0, &script.old) < 0)
    my_erno(3, "Tcgetattr fail\n");
  termios->c_cc[VMIN] = 1;
  termios->c_cc[VTIME] = 0;
  termios->c_lflag = ECHO;
  tcsetattr(0, TCSANOW, termios);
  termios->c_lflag &= ~(ECHO | ICANON);
}

void			init_winsize(t_winsize *win)
{
  if (ioctl(0, TIOCGWINSZ, &win) < 0)
    my_erno(3, "IOCTL fail\n");
}
