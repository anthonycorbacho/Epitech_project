#include <stdlib.h>

#include "fromlib.h"

int		pf_char_isnum(char s)
{
  return (s > 47 && s < 58);
}

int		pf_char_isprintable(char str)
{
  if ((str < 32) || (str > 126))
    return (0);
  else
    return (1);
}

char		*pf_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (*(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  *(dest + i) = *(src + i);
  return (dest);
}

char		*pf_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (n > 0 && *(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
      --n;
    }
  if (n > 0)
    *(dest + i) = '\0';
  return (dest);
}

char		*pf_strdup(char *str)
{
  char		*back;

  back = pf_xmalloc(sizeof(*back) * (pf_strlen(str) + 1));
  if (back == NULL)
    return (back);
  pf_strcpy(back, str);
  return (back);
}
