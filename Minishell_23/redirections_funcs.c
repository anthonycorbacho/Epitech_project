

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "llist.h"
#include "lstr.h"

#include "redirections.h"

/*
** Pipe redirection
*/
int		red_pipe(int olds[2], int toyos[2], char *s)
{
  s = s;
  pipe(toyos);
  olds[0] = olds[0];
  return (1);
}

/*
** File trunc redirection
*/
int		red_right(int olds[2], int toyos[2], char *s)
{
  toyos[1] = open(s, O_WRONLY | O_CREAT | O_TRUNC);
  if (toyos[1] < 0)
    {
      my_putstr_e("ERROR CREATING FILE\n");
      return (0);
    }
  toyos[0] = olds[0];
  return (1);
}

/*
** File append redirection
*/
int		red_d_right(int olds[2], int toyos[2], char *s)
{
  toyos[1] = open(s, O_WRONLY | O_CREAT | O_APPEND);
  if (toyos[1] < 0)
    {
      my_putstr_e("ERROR CREATING FILE\n");
      return (0);
    }
  toyos[0] = olds[0];
  return (1);
}

/*
** Opens a file
*/
int		red_left(int olds[2], int toyos[2], char *s)
{
  toyos[0] = open(s, O_RDONLY);
  if (toyos[0] < 0)
    {
      my_putstr_e("ERROR OPENING FILE\n");
      return (0);
    }
  toyos[1] = olds[1];
  return (1);
}

int		red_d_left(int olds[2], int toyos[2], char *s)
{
  toyos[0] = open(s, O_RDONLY);
  if (toyos[0] < 0)
    {
      my_putstr_e("ERROR OPENING FILE\n");
      return (0);
    }
  toyos[1] = olds[1];
  return (1);
}
