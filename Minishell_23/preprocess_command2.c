

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
** Returns a copy of the redirection operator
** and new point points after the redirec operator
*/
char		*find_first(char *s, char **new_pos)
{
  char		*ref[] = REDIRECTIONS;
  int		i;

  while (*s)
    {
      i = 0;
      while (ref[i] && my_strncmp(ref[i], s, my_strlen(ref[i])))
	++i;
      if (ref[i])
	{
	  *s = 0;
	  *new_pos = s + my_strlen(ref[i]);
	  return (my_strdup(ref[i]));
	}
      ++s;
    }
  *new_pos = s;
  return (NULL);
}

char		**list_to_charpppre(t_list *e)
{
  int		s;
  char		**ret;
  t_list	*backup;

  backup = e;
  s = get_list_size(e) + 1;
  ret = malloc(sizeof(*ret) * s + 1);
  s = 0;
  while (e)
    {
      if (((char *)e->data)[0])
	{
	  ret[s] = ((char *)e->data);
	  ++s;
	}
      else
	xfree(e->data);
      e = e->next;
    }
  ret[s] = NULL;
  free_list(backup);
  return (ret);
}

/*
** Parses a command line
** Returns a char ** containing the strings using the redirectors
** operators as separators
** the result is in reverse order
*/
char		**command_parser(char *s)
{
  t_list	*list;
  t_list	*elt;
  char		*new_pos;
  char		*operator;
  char		**ret;

  list = NULL;
  while (*s)
    {
      operator = find_first(s, &new_pos);
      elt = xmalloc(sizeof(*elt));
      list = my_insert_head(list, elt);
      elt->data = xmalloc(sizeof(*s) * (new_pos - s + 1));
      my_strncpy((char *) elt->data, s + (*s == ' '), new_pos - s);
      ((char *)elt->data)[new_pos - s - (*s == ' ')] = 0;
      if (operator)
	{
	  elt = xmalloc(sizeof(*elt));
	  list = my_insert_head(list, elt);
	  elt->data = operator;
	}
      s = new_pos;
    }
  ret = list_to_charpppre(list);
  return (ret);
}
