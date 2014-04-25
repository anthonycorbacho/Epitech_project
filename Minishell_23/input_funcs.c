#include <stdlib.h>
#include "lstr.h"

#include "termcaps.h"
#include "input.h"

/*
** Modifies the command line and the cursor pos according to the action
*/
void		key_enter()
{
}

void             key_delete()
{
  char		*s;

  s = command_line(NULL);
  if (s[cursor(-2)])
    shift_left(s + cursor(-2), 1);
}

void		key_backspace()
{
  char		*s;

  s = command_line(NULL);
  if (cursor(-2))
    {
      shift_left(s + cursor(-2) - 1, 1);
      cursor(cursor(-2) - 1);
    }
}

void		key_left()
{
  if (cursor(-2))
    cursor(cursor(-2) - 1);
}

void		key_right()
{
  char		*s;

  s = command_line(NULL);
  if (s[cursor(-2)])
    cursor(cursor(-2) + 1);
}
