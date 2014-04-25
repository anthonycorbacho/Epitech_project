#include <signal.h>
#include <stdlib.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>

#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "termcaps.h"
#include "input.h"
#include "mysh.h"
#include "my_ioctl.h"

/*
** Displays a line in the term
*/
void			display_line(t_caps_str *vars)
{
  struct winsize	w;
  int			off;

  w = get_dimensions(-1, -1);
  tputs(vars->cr, 1, my_outc);
  tputs(vars->dl, 1, my_outc);
  off = my_printf("%s%s", PROMPT, command_line(NULL)) - my_strlen(PROMPT);
  while (off-- - cursor(-2) > 0)
    tputs("\b", 1, my_outc);
}

/*
** Redirects the suspend signal on the yank command
*/
void			sigsuspend_redir(int num)
{
  num = num;
  cursor(-1);
  yank();
}

/*
** Inits the terminal with specific caracteristics
*/
struct termios		get_next_init(t_caps_str *vars)
{
  struct termios	backup_st;

  backup_st = get_conf(0);
  modify_conf(vars);
  signal(SIGWINCH, sigwinch);
  signal(SIGTSTP, sigsuspend_redir);
  sigwinch();
  return (backup_st);
}

/*
** Returns the func pointer correponding to the char v
** or NULL if not found
*/
void			(*get_input_modif(char *v))()
{
  int			i;

  i = 0;
  while (bindkey_bank_[i].func_pt)
    {
      if (bindkey_bank_[i].value && !my_strcmp(v, bindkey_bank_[i].value))
        return (bindkey_bank_[i].func_pt);
      ++i;
    }
  return (NULL);
}

/*
** Returns the command
*/
char			*get_next_command(const int fd)
{
  char			buffer[10];
  struct termios	backup_st;
  void			(*func_op)();
  int			r;

  cursor(0);
  command_line(malloc(sizeof(*(command_line(NULL))) * 10));
  command_line(NULL)[0] = 0;
  backup_st = get_next_init(retrieve_vars(NULL));
  display_line(retrieve_vars(NULL));
  func_op = NULL;
  while (func_op != key_enter && (r = read(fd, buffer, 9)))
    {
      buffer[r] = 0;
      func_op = get_input_modif(buffer);
      func_op ? func_op() :
	command_line(insert_string(command_line(NULL), buffer));
      display_line(retrieve_vars(NULL));
    }
  set_conf(backup_st, 0);
  signal(SIGWINCH, SIG_DFL);
  signal(SIGTSTP, SIG_DFL);
  my_putchar('\n');
  test_and_add_bindkey(command_line(NULL));
  return (command_line(NULL));
}
