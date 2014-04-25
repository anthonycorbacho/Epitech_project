
#include <stdlib.h>

#include "llist.h"
#include "lxsys.h"
#include "lstr.h"
#include "lmy.h"

#include "my_environ.h"

char		*get_env_var_value(t_list *env, char *name)
{
  char		*data;
  char		*ret;
  char		*recherche;

  ret = NULL;
  recherche = add_equal(name);
  data = my_find_elm_eq_in_list(env, recherche, my_env_cmp);
  if (data != NULL)
    ret = cut_first_part(data, "=");
  free(recherche);
  return (ret);
}

int		set_env_var_value(t_list **my_environ, char *varname, char *value)
{
  char		*recherche;
  char		*add;
  t_list	*node;
  t_list	*env;

  env = *my_environ;
  recherche = add_equal(varname);
  node = my_find_node_eq_in_list(env, recherche, my_env_cmp);
  add = xmalloc(sizeof(*add) * (my_strlen(recherche) + my_strlen(value) + 1));
  add = my_strcpy(add, recherche);
  add = my_strcat(add, value);
  add[my_strlen(recherche) + my_strlen(value)] = 0;
  if (node != NULL)
    {
      free(node->data);
      node->data = add;
    }
  else
    {
      node = xmalloc(sizeof(*node));
      node->data = add;
      *my_environ = my_insert_queue(env, node);
    }
  free(recherche);
  return (1);
}

int		unset_env_var(t_list **env, char *varname)
{
  char		*recherche;

  if (!my_strcmp(varname, "*"))
    {
      completely_free_list(*env, free);
      *env = NULL;
    }
  else
    {
      recherche = add_equal(varname);
      my_rm_all_eq_from_list(env, recherche, my_env_cmp);
      free(recherche);
    }
  return (0);
}
