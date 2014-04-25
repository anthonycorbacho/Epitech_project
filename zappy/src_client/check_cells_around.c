/*
** check_cells_around.c for check_cells_around
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Sat Apr 17 13:54:07 2010 pierre1 rolland
** Last update Sun Apr 25 17:28:14 2010 thomas1 salomon
*/

#include		"client.h"
#include		"get_XY_from_cell.h"
#include		"lstr.h"
#include		"client_movement.h"

#include		"lmy_printf.h"

/* Check cells around the player to see if there is the seeked item.
   RETURN VALUES :
   The cell's number if the item is found
   -1 if the item isn't found
*/
int			check_cells_around(char *see_content, char *seek)
{
  int			cell;
  int			length_seek;

  cell = 0;
  length_seek = my_strlen(seek);
  while (*see_content != '\0')
    {
      if (!my_strncmp(see_content, seek, length_seek))
	return (cell);
      if (*see_content == ',')
	cell++;
      see_content++;
    }
  return (-1);
}

/* Move on a cell
   RETURN VALUES : 1 if successful, -1 if not*/
int			pseudo_clever_move(char *see_content, char *seek,
					   t_player *p)
{
  int			cell;
  int			x;
  int			y;

  if ((cell = check_cells_around(see_content, seek)) == -1)
    return (-1);
  y = get_Y_from_cell(cell);
  x = get_X_from_cell(cell, y);
  while (y-- > 0)
    move(p, "avance\n");
  if (x < 0)
    {
      move(p, "gauche\n");
      x = -x;
    }
  else if (x > 0)
    move(p, "droite\n");
  while (x-- > 0)
    move(p, "avance\n");
  return (1);
}
