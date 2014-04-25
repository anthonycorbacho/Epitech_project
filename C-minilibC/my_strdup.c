#include <stdlib.h>

char			*my_strdup(char *str)
{
  char			*back;

  back = malloc(sizeof(*back) * (my_strlen(str) + 1));
  if (back == NULL)
    return (back);
  my_strcpy(back, str);
  return (back);
}
