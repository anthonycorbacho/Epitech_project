#include <stdlib.h>
#include <unistd.h>

#include "fromlib.h"

void		*pf_xmalloc(int size)
{
  void		*alloc;

  alloc = malloc(size);
  if (alloc == NULL)
    {
      pf_putstr_e("MALLOC FAILED");
      exit(-1);
    }
  else
    return (alloc);
}

int		pf_char_is_in_base(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i] && (base[i] != c))
    i++;
  if (base[i] == c)
    return (i);
  else
    return (-1);
}

char		*pf_shift_left(char *s, int n)
{
  char		*backup;

  backup = s;
  if (n < 1)
    return (s);
  if (s == NULL)
    return (NULL);
  while (*(s + n))
    {
      *s = *(s + n);
      ++s;
    }
  *s = 0;
  return (backup);
}

void		pf_putchar(char c)
{
  write(1, &c, 1);
}

int		pf_putstr(char *str)
{
  char		*s;

  s = str;
  while (*s)
    {
      pf_putchar(*s);
      ++s;
    }
  return (1);
}
