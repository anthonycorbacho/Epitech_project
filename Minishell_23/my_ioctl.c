

#include <sys/ioctl.h>
#include <termios.h>
#include <termcap.h>
#include <unistd.h>

#include "lmy_printf.h"
#include "lstr.h"

#include "termcaps.h"
#include "my_ioctl.h"

struct termios		get_conf(int fd)
{
  struct termios	st;

  if (ioctl(fd, TIOCGETA, &st) < 0)
    write(1, "ERREUR GET IOCTL\n", 10);
  return (st);
}

void			set_conf(struct termios st, int fd)
{
  if (ioctl(fd, TIOCSETA, &st) < 0)
    write(1, "ERREUR SET IOCTL\n", 10);
}

/*
** Modifies the tty conf
*/
void			modify_conf()
{
  struct termios	st;

  st = get_conf(0);
  st.c_lflag &= ~ICANON;
  st.c_lflag &= ~ECHO;
  st.c_cc[VMIN] = 1;
  set_conf(st, 0);
}

/*
** Returns the size of the term
** if x == y != -1 : fixes the size of the term
*/
struct winsize		get_dimensions(int x, int y)
{
  static int		sx = 0;
  static int		sy = 0;
  struct winsize	w;

  if (x != -1 && y != -1)
    {
      sx = x;
      sy = y;
    }
  w.ws_row = sx;
  w.ws_col = sy;
  return (w);
}

/*
** Terminal redimension event
*/
void			sigwinch()
{
  struct winsize	w;
  if (ioctl(0, TIOCGWINSZ, &w) >= 0)
    get_dimensions(w.ws_row, w.ws_col);
  else
    my_printf("ERROR SIGWINCH\n");
}
