#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

#include "lmy_printf.h"
#include "unistd.h"

#include "termcaps.h"

int		my_outc(int c)
{
  char		d;

  d = (char) c;
  write(1, &d, 1);
  return (0);
}

char		*xtgetstr(char *cap, char **area)
{
  char		*capstr;

  if ((capstr = tgetstr(cap, area)) == NULL)
    {
      my_printf("%s%s\n", "PROBLEM GETTING CAPS STR ", cap);
      exit(1);
    }
  return (capstr);
}

t_caps_str	*get_variables(char **area, char **term, char bp[1024])
{
  t_caps_str	*vars;

  vars = malloc(sizeof(*vars));
  if ((*term = getenv("TERM")) == NULL)
    {
      my_printf("can't determine terminal\n");
      exit(1);
    }
  if (tgetent(bp, *term) != 1)
    {
      my_printf("problem with tgetent\n");
      exit(1);
    }
  vars->cm = xtgetstr("cm", area);
  vars->clr_scr = xtgetstr("cl", area);
  vars->cr = xtgetstr("cr", area);
  vars->up = xtgetstr("up", area);
  vars->doi = xtgetstr("do", area);
  vars->dl = xtgetstr("dl", area);
  vars->vi = xtgetstr("vi", area);
  vars->ve = xtgetstr("ve", area);
  return (vars);
}

t_caps_str	*retrieve_vars(t_caps_str *vars)
{
  static	t_caps_str *v;
  if (vars)
    v = vars;
  return v;
}
