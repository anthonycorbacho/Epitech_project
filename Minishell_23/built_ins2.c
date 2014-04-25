#include <stdlib.h>
#include <unistd.h>

#include "llist.h"
#include "lstr.h"

#include "built_ins.h"
#include "my_environ.h"
#include "my_getwd.h"

/*
**Sets an env variable
**Overwrites it if it exists
*/
int		built_in_setenv(char *command, t_list **my_environ)
{
  char		*varname;
  char		*tmp;

  varname = get_first_part(command, " \t");
  tmp = cut_first_part(command, " \t");
  if (varname == NULL || tmp == NULL || my_chars_count(" \t", tmp))
    {
      my_putstr(SETENV_BAD_USAGE);
      return (-1);
    }
  set_env_var_value(my_environ, varname, tmp);
  free(tmp);
  free(varname);
  return (0);
}

/*
**Unsets environnment variables
**Accepts several arg names
** * deletes everything
*/
int		built_in_unsetenv(char *command, t_list **my_environ)
{
  char		**args;
  int		i;

  i = 0;
  args = my_str_sep(command, " \t");
  if (my_charpp_len(args) == 0)
    {
      my_putstr("unsetenv: ");
      my_putstr(TOO_FEW_ARGS);
      my_putchar('\n');
    }
  else
    while (args[i])
      unset_env_var(my_environ, args[i++]);
  free(args);
  return (0);
}

/*
**Sets en environnment variable
**Creates it if it doesnt exist
*/
int		built_in_env(char *path, t_list **my_environ)
{
  t_list	*env;

  if (path)
    path = NULL;
  env = (*my_environ);
  while (env != NULL)
    {
      my_putstr(env->data);
      my_putchar('\n');
      env = env->next;
    }
  return (0);
}

/*
**Displays the current working directory
*/
int		built_in_pwd()
{
  char		*wd;

  wd = my_getwd();
  my_putstr(wd);
  my_putchar('\n');
  free(wd);
  return (0);
}
