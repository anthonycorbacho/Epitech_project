#include <stdlib.h>
#include <unistd.h>

#include "llist.h"
#include "lstr.h"

#include "built_ins.h"
#include "my_getwd.h"
#include "my_environ.h"

t_built		builtins[] = {{"cd", 2, built_in_cd},
			      {"env", 2, built_in_env},
			      {"setenv", 2, built_in_setenv},
			      {"unsetenv", 2, built_in_unsetenv},
			      {"exit", 2, built_in_exit},
			      {"pwd", 0, built_in_pwd},
			      {NULL, 0, NULL}};

void		update_pwd(t_list **my_environ)
{
  char		*wd;

  wd = my_getwd();
  set_env_var_value(my_environ, "PWD", wd);
  free(wd);
}

void		my_cd(char **args, char **s, t_list **my_environ, char *wd)
{
  if (!my_strcmp(args[0], "-"))
    {
      if ((*s = get_env_var_value(*my_environ, "-")) != NULL)
	{
	  set_env_var_value(my_environ, "-", wd);
	  chdir(*s);
	}
      else
	my_putstr(BT_IN_CD_NO_SUCH_FILE);
    }
  else
    {
      if (chdir(args[0]))
	{
	  my_putstr(args[0]);
	  my_putstr(BT_IN_CD_NO_SUCH_FILE);
	}
      else
	set_env_var_value(my_environ, "-", wd);
    }
}

int		built_in_cd(char *path, t_list **my_environ)
{
  char		**args;
  char		*s;
  char		*wd;

  s = NULL;
  wd = my_getwd();
  args = my_str_sep(path , " \t");
  if (args && my_charpp_len(args) > 1)
    my_putstr(BT_IN_CD_TOO_MANY_ARGS);
  else if (args && my_charpp_len(args) == 1)
    my_cd(args, &s, my_environ, wd);
  else
    {
      s = get_env_var_value(*my_environ, "HOME");
      if (s != NULL)
	chdir(s);
      set_env_var_value(my_environ, "-", wd);
    }
  if (s != NULL)
    free(s);
  if (args != NULL)
    free(args);
  update_pwd(my_environ);
  free(wd);
  return (0);
}

int		built_in_exit(char *command, t_list **my_environ)
{
  my_environ = my_environ;
  command = command;
  return (-1);
}

/*
** Checks if the command is a built in
** 0  => not a built in
** -1 => built in exit
** 1  => regular built in
*/
int		exec_built_in(char *command, t_list **my_environ)
{
  char		*tmp;
  int		i;
  int		(*bt_in)();

  i = 0;
  tmp = get_first_part(command, " ");
  while (builtins[i].name && my_strcmp(builtins[i].name, tmp))
    ++i;
  free(tmp);
  if (builtins[i].name)
    {
      tmp = cut_first_part(command, " ");
      bt_in = builtins[i].func_builtin;
      if (builtins[i].ac == 1)
	bt_in(tmp);
      else
	bt_in(tmp, my_environ);
      free(tmp);
    }
  else
    return (0);
  return ((bt_in == built_in_exit) ? -1 : 1);
}
