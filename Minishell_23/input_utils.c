#include <stdlib.h>

#include "lstr.h"
#include "lxsys.h"

#include "termcaps.h"
#include "input.h"

/*
** Keeps a copy of the buffer after the cursor pos
** If cursor == -1 => returns the buffer content
*/
char			*copy_buffer(int cursor)
{
  static	char *buffer = NULL;
  char		*s;

  s = command_line(NULL);
  if ( s && *s && cursor != -1)
    {
      xfree(buffer);
      buffer = my_strdup(s + cursor);
    }
  if (buffer)
    return (buffer);
  else
    return ("");
}

/*
** Inserts the content of the buffer in the line at the cursor position
*/
char			*insert_string(char *line, char *buffer)
{
  char			c[2];
  char			*ret;
  int			size;

  size = my_strlen(buffer) + my_strlen(line);
  ret = malloc(sizeof(*ret) * (size + 1));
  c[0] = line[cursor(-2)];
  line[cursor(-2)] = 0;
  my_strcpy(ret, line);
  my_strcat(ret, buffer);
  c[1] = 0;
  my_strcat(ret, c);
  if (c[0])
    my_strcat(ret, line + cursor(-2) + 1);
  free(line);
  ret[size] = 0;
  size = cursor(-2) + my_strlen(buffer);
  cursor(size);
  return (ret);
}
