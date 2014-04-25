/*
** get_XY_from_cell.c for get_XY_from_cell
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Sat Apr 17 15:09:11 2010 pierre1 rolland
** Last update Sun Apr 25 17:29:37 2010 thomas1 salomon
*/

int		get_Y_from_cell(int cell)
{
  int		y;
  int		i;

  i = 1;
  y = 0;
  while (cell > 0)
    {
      i += 2;
      cell -= i;
      y++;
    }
  return (y);
}

int		get_X_from_cell(int cell, int y)
{
  int		x;
  int		i;

  x = 0;
  i = 1;
  while (y > 0)
    {
      cell -= i;
      y--;
      x--;
      i += 2;
    }
  while (cell > 0)
    {
      x++;
      cell--;
    }
  return (x);
}
