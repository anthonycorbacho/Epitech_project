#include <stdlib.h>

#include "lstr.h"

#include "termcaps.h"
#include "input.h"

/*
** Kills the whole line
** Copies the line and modifies the static reference
*/
void		kill_whole_line()
{
  char		*s;

  s = command_line(NULL);
  copy_buffer(0);
  *s = 0;
  cursor(0);
}

/*
** Kills the string after the cursor
** Copies the line and modifies the static reference
*/
void		kill_line()
{
  char		*s;

  s = command_line(NULL);
  if (s[cursor(-2)])
    {
      copy_buffer(cursor(-2));
      s[cursor(-2)] = 0;
    }
}

/*
** Clear screen
*/
void		clear_screen()
{
  my_putstr(retrieve_vars(NULL)->clr_scr);
}

/*
** Pastes the content of the buffer to the current pos
*/
void		yank()
{
  char		*buffer;

  buffer = copy_buffer(cursor(-2));
  if (cursor(-2) == -1)
    cursor(my_strlen(command_line(NULL)));
  command_line(insert_string(command_line(NULL), buffer));
  display_line(retrieve_vars(NULL));
}

void		null_action()
{
}
