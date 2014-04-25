

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "mysh.h"

#include "redirections.h"
#include "preprocess.h"

/*
** mode == 1 checks if the redir is righty
** mode == 0 checks if the redir is lefty
** Return 1 if success, 0 otherwise
*/
int		is_righty_or_lefty(int mode, char *s)
{
  int		(*fc)();

  fc = get_redirec(s);
  if (mode)
    {
      if (fc == red_right || fc == red_d_right)
	return (1);
      else
	return (0);
    }
  else
    {
      if (fc == red_left || fc == red_d_left)
	return (1);
      else
	return (0);
    }
}

/*
** Detects ambiguous right redirection in the expression
*/
int		right_ambiguous(char **command)
{
  int		has;
  int		i;

  i = my_charpp_len(command) - 1;
  has = 0;
  while (i >= 0)
    {
      if (has && get_redirec(command[i]))
	{
	  my_putstr_e("Ambiguous output redirect.\n");
	  return (0);
	}
      if (get_redirec(command[i]) && is_righty_or_lefty(1, command[i]))
	has = 1;
      --i;
    }
  return (1);
}

/*
** Detects ambiguous left redirection in the expression
*/
int		left_ambiguous(char **command)
{
  int		has;
  int		i;

  i = my_charpp_len(command) - 1;
  has = 0;
  while (i >= 0)
    {
      if (has && get_redirec(command[i]) && is_righty_or_lefty(0, (command[i])))
	{
	  my_putstr_e("Ambiguous input redirect.\n");
	  return (0);
	}
      if (get_redirec(command[i]) && is_righty_or_lefty(0, command[i]))
	has = 1;
      --i;
    }
  return (1);
}

/*
** Checks if the command is valid
** Returns 1 if success, 0 otherwise
*/
int		check_command_validity(char **command)
{
  int		possible;
  int		i;

  i = my_charpp_len(command) - 1;
  possible = 0;
  while (i >= 0)
    {
      if (get_redirec(command[i]))
	{
	  if (!possible || !i)
	    {
	      my_putstr_e("Invalid null command.\n");
	      return (0);
	    }
	  possible = 0;
	}
      else
	possible = 1;
      --i;
    }
  return (left_ambiguous(command) && right_ambiguous(command));
}
