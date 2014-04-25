#include <stdlib.h>

#include "fromlib.h"

#include "formats.h"
#include "displays.h"
#include "get_convertion.h"

/*
** Convertion values
** Links the convertion symbols to their corresponding function
*/
t_convertion	convertion_ops[] = {{"di", "INT", display_int},
				    {"Ssc", "STR", display_str},
				    {"Xuoxbp", "UINT", display_uint},
				    {NULL, NULL, NULL}};

/*
** Returns the address of the function
** corresponding to the convertion symbol
*/
int		(*get_convertion(char *s))()
{
  int		i;

  i = 0;
  while (convertion_ops[i].symbols)
    {
      if (pf_char_is_in_base(*s, convertion_ops[i].symbols) != -1)
	{
	  pf_shift_left(s, 1);
	  return (convertion_ops[i].display_func);
	}
      ++i;
    }
  return (NULL);
}

int		(*get_convertion_by_type(char *s))()
{
  int		i;

  i = 0;
  while (convertion_ops[i].symbols)
    {
      if (!pf_strcmp(s, convertion_ops[i].type))
	return (convertion_ops[i].display_func);
      ++i;
    }
  return (NULL);
}
