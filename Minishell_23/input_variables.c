#include <stdlib.h>

#include "termcaps.h"
#include "input.h"

/*
** Sets the value of the cursor if c != -2
** Returns the cursor value
*/
int		cursor(int c)
{
  static int	cursor_ = 0;

  if (c != -2)
    cursor_ = c;
  return (cursor_);
}

/*
** Returns the line address if NULL
** Sets it to the specified value otherwise
*/
char		*command_line(char *s)
{
  static char	*command_line_ = NULL;

  if (s)
    command_line_ = s;
  return (command_line_);
}
