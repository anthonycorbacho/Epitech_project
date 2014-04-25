#include <stdlib.h>

#include "fromlib.h"

#include "get_precision_and_field.h"

/*
**Returns the argument precision
*/
int		get_precision(char *s)
{
  char		*backup;
  char		*num;
  int		i;

  backup = s;
  if (*s == '.' && pf_char_isnum(*(s + 1)))
    {
      num = pf_xmalloc(sizeof(*num) * 10);
      ++s;
      i = 0;
      while (pf_char_isnum(*s))
	{
	  num[i++] = *s;
	  s++;
	}
      num[i] = 0;
      pf_shift_left(backup, i + 1);
      i = pf_atoi(num);
      free(num);
      return (i);
    }
  return (-1);
}

/*
**Returns the field width
*/
int		get_field_width(char *s)
{
  char		*backup;
  char		*num;
  int		i;

  backup = s;
  if (pf_char_isnum(*s))
    {
      num = pf_xmalloc(sizeof(*num) * 10);
      i = 0;
      while (pf_char_isnum(*s))
	{
	  num[i++] = *s;
	  s++;
	}
      num[i] = 0;
      pf_shift_left(backup, i);
      i = pf_atoi(num);
      free(num);
      return (i);
    }
  return (0);
}
