#include <stdlib.h>

#include "fromlib.h"

char		**pf_str_sep(char *s, char *delimiters)
{
  char		**ret;
  char		*in;
  int		i;

  if (s == NULL || *s == 0)
    return (NULL);
  ret = pf_xmalloc(sizeof(*ret) * (pf_chars_count(delimiters, s) + 2));
  i = 0;
  in = s;
  while (*(s++))
    if (pf_char_is_in_base(*(s - 1), delimiters) != -1)
      {
	if (in != s - 1)
	  {
	    ret[i++] = in;
	    *(s - 1) = 0;
	    in = s;
	  }
	else
	  ++in;
      }
  if (*in)
    ret[i++] = in;
  ret[i] = NULL;
  return (ret);
}

int		pf_chars_count(char *base, char *s)
{
  int		occur;

  occur = 0;
  if (s == NULL)
    return (0);
  while (*s)
    {
      if (pf_char_is_in_base(*s, base) != -1)
	++occur;
      ++s;
    }
  return (occur);
}

int		pf_atoi(char *a)
{
  long long	p;
  int		v;

  v = 0;
  p = pf_power(10, pf_strlen(a) - 1);
  while (*a)
    {
      v += (*a - 48) * p;
      p /= 10;
      a++;
    }
  return (v);
}

long long	pf_power(int nb, int p)
{
  int		i;
  long long	ret;

  i = 0;
  ret = 1;
  while (i < p)
    {
      ret *= nb;
      ++i;
    }
  return (ret);
}
