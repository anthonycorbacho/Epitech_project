/*
** position.c for position in /home/matt/work/my_zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sun Mar 21 15:26:34 2010 mathieu1 lornac
** Last update Tue Apr 13 18:42:50 2010 damien1 coppel
*/

#include <stdlib.h>

#include "llist.h"
#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "position.h"

/*
** Extract the coordinates of a string formated as:
** X Y\n
*/
t_pos			*extract_coordinates_from_str(char *ss)
{
  t_pos			*pos;
  char			**vals;
  char			*s;

  s = my_strdup(ss);
  pos = xmalloc(sizeof(*pos));
  vals = my_str_sep(s, " \n");
  pos->x = my_atoi(vals[0]);
  pos->y = my_atoi(vals[1]);
  xfree(vals);
  free(s);
  return (pos);
}

/*
** Translates the coordinates into a string formated as:
** X Y\n
*/
char			*extract_coordinates_from_pos(t_pos *p)
{
  char			*str;
  char			*tmp;

  str = xmalloc(sizeof(*str) * MESS_MAX_SIZE);  
  tmp = my_sprintf(p->x);
  my_strcpy(str, tmp);
  my_strcat(str, " ");
  xfree(tmp);
  tmp = my_sprintf(p->y);
  my_strcat(str, tmp);
  my_strcat(str, "\n");
  xfree(tmp);
  return (str);
}

/*
** Sets the position of a player
** dest, source
*/
void			set_pos(t_pos *dest, t_pos *source)
{
  dest->x = source->x;
  dest->y = source->y;
}

/*
** Compares 2 positions
** returns 1 if pos identical, 0 otherwise
*/
int			cmp_pos(t_pos *dest, t_pos *source)
{
  return ((dest->x == source->x) && (dest->y == source->y));
}

/*
** Position display (x: %d y: %d\n)
*/
void			print_pos(t_pos *p)
{
  my_printf("X: %d Y: %d\n", p->x, p->y);
}
