
#include <signal.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "my_environ.h"
#include "mysh_errors.h"

/*
**Looks for the exe in the dirs contained in the variable path
**Return NULL if it doesnt exist
*/
char		*get_exe_path(char *c, t_list **my_environ)
{
  char		**paths;
  char		*tmp;
  int		i;
  char		*p;

  p = get_env_var_value(*my_environ, "PATH");
  paths = (p == NULL) ? (NULL) : my_str_sep(p, ":");
  i = 0;
  while ((paths != NULL) && (paths[i] != NULL))
    {
      tmp = xmalloc(sizeof(*tmp) * (my_strlen(paths[i]) + my_strlen(c) + 2));
      my_strcpy(tmp, paths[i]);
      ++i;
      if (tmp[my_strlen(tmp) - 1] != '/')
	my_strcat(tmp, "/");
      my_strcat(tmp, c);
      if (!access(tmp, X_OK))
      	{
	  free(paths);
	  free(p);
	  return (tmp);
      	}
      free(tmp);
    }
  return (NULL);
}

int		folder_test(char *f, t_list *env)
{
  char		*pwd;

  if (!chdir(f))
    {
      pwd = get_env_var_value(env, "PWD");
      chdir(pwd);
      free(pwd);
      return (1);
    }
  return (0);
}

/*
**Executes the specified command
*/
void		executer(char *command, t_list **my_environ)
{
  char		*exe;
  char		*path;
  char		**args;
  char		**env;
  int		folder;

  exe = NULL;
  folder = folder_test(exe, *my_environ);
  path = NULL;
  exe = get_first_part(command, " \t");
  if (!eaccess(exe, X_OK) && ((exe[0] == '.') || exe[0] == '/'))
    path = exe;
  else if (exe[0] != '.' && exe[0] != '/' && !folder)
    path = get_exe_path(exe, my_environ);
  args = my_str_sep(command, " \t");
  env = list_to_charpp(*my_environ);
  if (path && !eaccess(path, X_OK))
    execve(path, args, env);
  if (!folder || exe[my_strlen(exe) - 1] != '/')
    COMMAND_NOT_FOUND_ERROR(exe);
  else
    PERMISSION_DENIED_ERROR(exe);
  xfree3(args, exe, env);
  exit(1);
}
