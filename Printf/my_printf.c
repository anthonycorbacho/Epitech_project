#include <stdlib.h>
#include <stdarg.h>

#include "fromlib.h"

#include "formats.h"
#include <get_formats.h>

#include "my_printf.h"

/*
** Displays all the arguments contained int the lists
** Returns the nb of char displayed
*/
int		display(t_list *form, t_list *arg)
{
  int		(*disp_func)();
  t_format	*f;
  int		occur;

  occur = 0;
  while (form)
    {
      f = form->data;
      disp_func = f->disp_func;
      if (f->explicite)
	occur += disp_func(&(f->explicite), f);
      else if (disp_func)
	{
	  occur += disp_func(arg->data, f);
	  arg = arg->next;
	}
      form = form->next;
    }
  return (occur);
}

/*
**Retrieve an arg
*/
void		ret_it(t_format *f, va_list *ap, t_list *elt)
{
  int		*s;
  long long	*s2;

  if (f->size_on_stack == 4)
    {
      s = malloc(sizeof(*s));
      *s = va_arg(*ap, int);
      elt->data = s;
    }
  else
    {
      s2 = malloc(sizeof(*s2));
      *s2 = va_arg(*ap, long long);
      elt->data = s2;
    }
}

/*
**Puts the printf args into a list and returns it
*/
t_list		*retrieve_var_args(va_list ap, t_list *formats)
{
  t_format	*f;
  t_list	*argument_list;
  t_list	*elt;

  argument_list = NULL;
  while (formats)
    {
      f = formats->data;
      if ((f->explicite) == NULL)
	{
	  elt = malloc(sizeof(*elt));
	  ret_it(f, &ap, elt);
	  argument_list = pf_insert_queue(argument_list, elt);
	}
      formats = formats->next;
      }
  return (argument_list);
}

int		my_printf(char *format, ...)
{
  int		occur;
  t_list	*format_list;
  t_list	*argument_list;
  va_list	ap;

  occur = 0;
  if (format == NULL)
    {
      pf_putstr("(NULL)");
      return (0);
    }
  format = pf_strdup(format);
  format_list = get_formats(format);
  va_start(ap, format);
  argument_list = retrieve_var_args(ap, format_list);
  occur = display(format_list, argument_list);
  va_end(ap);
  free(format);
  pf_completely_free_list(format_list,free);
  pf_completely_free_list(argument_list,free);
  return (occur);
}
