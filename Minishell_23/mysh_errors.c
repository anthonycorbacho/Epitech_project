

#include "lstr.h"

#include "mysh_errors.h"

void		command_not_found(char *s)
{
  my_putstr(s);
  my_putstr(": command not found\n");
}

void		permission_denied(char *s)
{
  my_putstr(s);
  my_putstr(": Permission denied\n");
}

void		other_signal_e(char *s)
{
  my_putstr_e(s);
  my_putstr_e(": Permission denied\n");
}
