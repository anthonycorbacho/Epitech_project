
#include <stdlib.h>

#include "llist.h"
#include "lstr.h"
#include "lmy.h"
#include "lxsys.h"

#include "my_environ.h"

t_list		*prepare_environ()
{
  extern char	**environ;
  t_list	*my_environ;
  int		i;
  char		*s;

  my_environ = my_params_in_list_dup(my_charpp_len(environ), environ);
  s = get_env_var_value(my_environ, "SHLVL");
  i = (s == NULL) ? (0) : (my_atoi(s));
  if (s != NULL)
    free(s);
  s = my_sprintf(i + 1);
  set_env_var_value(&my_environ, "SHLVL", s);
  free(s);
  return (my_environ);
}

int		my_env_cmp(char *s1, char *s2)
{
  while (*s1 && (*s1 == *s2))
    {
      s1++;
      s2++;
    }
  return (*s1);
}

char		*add_equal(char *name)
{
  char		*ret;

  ret = xmalloc(sizeof(*ret) * (my_strlen(name) + 2));
  ret = my_strcpy(ret, name);
  ret[my_strlen(name)] = '=';
  ret[my_strlen(name) + 1] = 0;
  return (ret);
}

void		liberer_environ(t_list *my_environ)
{
  completely_free_list(my_environ, free);
}
