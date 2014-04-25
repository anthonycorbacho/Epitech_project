#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "llist.h"
#include "lstr.h"

#include "redirections.h"

t_redirec	redirec[] = {
  {">>", red_d_right},
  {"<<", red_d_left},
  {"<", red_left},
  {">", red_right},
  {"|", red_pipe},
  {NULL, NULL}};

/*
** Return a pointer on the redirec function
** NULL if not found
*/
int		(*get_redirec(char *s))()
{
  int		i;

  i = 0;
  while (redirec[i].name && my_strcmp(redirec[i].name, s))
    ++i;
  return (redirec[i].func_op);
}
