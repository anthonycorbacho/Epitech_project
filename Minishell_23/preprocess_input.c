

#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "my_environ.h"
#include "mysh.h"

#include "preprocess.h"

/*
** Replace the tild by the HOME value
** frees the or var if a tild is present
*/
char		*replace_tilds(char *cmd, t_list **my_environ)
{
  char		**args;
  char		*ret;
  char		*d;
  int		i;

  d = get_env_var_value(*my_environ, "HOME");
  if (d == NULL || !(*cmd))
    return (cmd);
  args = my_str_sep(cmd, " \t");
  ret = xmalloc(sizeof(*ret) * (my_strlen(cmd) + (my_charpp_len(args) + 2) *
	((d == NULL) ? (0) : my_strlen(d))));
  ret[0] = 0;
  i = 0;
  while (args[i])
    {
      if (args[i][0] == '~')
	my_strcat(my_strcat(ret, d), args[i] + 1);
      else
	my_strcat(ret, args[i]);
      if (args[++i] != NULL)
	my_strcat(ret, " ");
    }
  xfree3(args, d, cmd);
  return (ret);
}

/*
** Removes all unnecessary spaces and tabs
*/
char		*remove_spaces_and_tabs(char *s)
{
  char		*ret;
  char		*save;

  if (s == NULL)
    return (NULL);
  ret = malloc(sizeof(*ret) * (my_strlen(s) + 1));
  save = ret;
  while (*s)
    {
      while (*s && my_char_is_in_base(*s, " \t") != -1)
	++s;
      while (*s && my_char_is_in_base(*s, " \t") == -1)
	{
	  *ret = *s;
	  ++s;
	  ++ret;
	}
      if (*s)
	{
	  *ret = ' ';
	  ++ret;
	}
    }
  *ret = 0;
  return (save);
}

/*
** Removes useless spaces ans tabs
** Replaces the tilds where it has to be
*/
char		**preprocess_expr(char **s, t_list **my_environ)
{
  char		*tmp;
  char		**ret;
  int		i;

  if (!s || *s == 0)
    return (NULL);
  tmp = remove_spaces_and_tabs(*s);
  free(*s);
  *s = replace_tilds(tmp, my_environ);
  ret = my_str_sep(*s , ";");
  if (!ret)
    {
      ret = xmalloc(sizeof(*ret) * 2);
      ret[1] = NULL;
      ret[0] = *s;
    }
  i = 0;
  while (ret[i])
    {
      if (ret[i][0] == ' ')
	ret[i] = ret[i] + 1;
      ++i;
    }
  return (ret);
}
