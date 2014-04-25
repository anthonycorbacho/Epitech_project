

#include <signal.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>

#include "llist.h"
#include "lmy.h"
#include "lstr.h"
#include "lxsys.h"

#include "preprocess.h"
#include "termcaps.h"
#include "input.h"
#include "my_environ.h"
#include "my_getwd.h"
#include "my_ioctl.h"
#include "mysh.h"
#include "mysh_errors.h"
#include "redirections.h"

/*
** Catches the interrupt signal
*/
void		interrupt_sig(int val)
{
  char		*s;

  s = command_line(NULL);
  *s = 0;
  cursor(0);
  val = val;
  my_putchar('\n');
  display_line(retrieve_vars(NULL));
}

/*
** Executes all the independant commands
*/
int		treat_commands(char **commands, t_list **my_environ)
{
  int		i;
  char		**instrucs;
  int		toyos[2];
  int		exit;

  exit = 0;
  toyos[0] = 0;
  toyos[1] = 1;
  i = 0;
  while (!exit && commands && commands[i] && commands[i][0])
    {
      instrucs = command_parser(commands[i]);
      if (check_command_validity(instrucs))
	exit = create_pipes_and_exec(instrucs, 0, my_environ, toyos);
      free_charpp(instrucs);
      ++i;
    }
  return (exit);
}

/*
** Main procedure
*/
int			main()
{
  t_list		*my_environ;
  char			*command;
  char			**commands;
  int			exiting;
  char			ar[4096];
  char			*term;
  char			bp[1024];
  char			*area;
  t_caps_str		*vars;

  signal(SIGINT, interrupt_sig);
  area = ar;
  vars = get_variables(&area, &term, bp);
  retrieve_vars(vars);
  my_environ = prepare_environ();
  exiting = 0;
  while (!exiting && (command = get_next_command(0)))
    {
      commands = preprocess_expr(&command, &my_environ);
      exiting = treat_commands(commands, &my_environ);
      xfree2(command, commands);
    }
  liberer_environ(my_environ);
  free(vars);
  return (1);
}
