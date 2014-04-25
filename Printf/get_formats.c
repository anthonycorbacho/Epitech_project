#include <stdlib.h>

#include "fromlib.h"

#include "attributs.h"
#include "formats.h"
#include "get_convertion.h"
#include "get_formats.h"
#include "get_len_modif.h"
#include "get_precision_and_field.h"

t_format	*malloc_format()
{
  t_format	*format;

  format = pf_xmalloc(sizeof(*format));
  format->explicite = NULL;
  format->convertion = 0;
  format->field_width = -1;
  format->len_modif = -1;
  format->size_on_stack = 4;
  format->disp_func = NULL;
  return (format);
}

/*
**Add to the list the explicite string provided in the format string
*/
t_list		*add_rest(char *s, t_list *list)
{
  t_format	*format;
  t_list	*elt;

  format = malloc_format();
  elt = pf_xmalloc(sizeof(*elt));
  elt->data = format;
  format->convertion = 's';
  format->precision = pf_strlen(s);
  format->explicite = s;
  format->disp_func = get_convertion_by_type("STR");
  return (pf_insert_queue(list, elt));
}

/*
**Treat arg
*/
t_list		*treat_arg(t_list *list, char *str)
{
  t_format	*format;
  t_list	*elt;

  format = malloc_format();
  format->attribut = get_attribut(str);
  format->field_width = get_field_width(str);
  format->precision = get_precision(str);
  format->len_modif = get_len_modif(str);
  format->convertion = str[0];
  format->disp_func = get_convertion(str);
  if (format->len_modif & mod_ll_v && 
      (pf_char_is_in_base(format->convertion, "diouxXb") != -1))
    format->size_on_stack = sizeof(long long);
  else
    format->size_on_stack = sizeof(int);
  elt = pf_xmalloc(sizeof(*elt));
  elt->data = format;
  return (pf_insert_queue(list, elt));
}

void		init(t_list **list, int *i, char **old, char *s)
{
  *list = NULL;
  *i = 0;
  *old = s;
}

/*
**Retrieve a list of t_format corresponding to
**the format chain passed in parameter
*/
t_list		*get_formats(char *s)
{
  char		**args;
  int		i;
  t_list	*list;
  char		*old;
  char		*tmp;

  init(&list, &i, &old, s);
  args = pf_str_sep(s, "%");
  while (args && args[i])
    {
      tmp = old;
      while (args[i] - tmp > 1)
	{
	  list = add_rest("%", list);
	  tmp += 2;
	}
      tmp = args[i] + pf_strlen(args[i]);
      if ((args[i++] - old) % 2)
	list = treat_arg(list, args[i - 1]);
      list = (args[i - 1][0]) ? (add_rest(args[i - 1], list)) : (list);
      old = tmp;
    }
  free(args);
  return (list);
}
