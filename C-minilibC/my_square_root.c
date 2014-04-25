/*
** my_square_root.c for my square root in /home/lornac_a/work/Day5
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Oct  9 18:18:34 2009 mathieu1 lornac
** Last update Sun Oct 11 21:38:54 2009 mathieu1 lornac
*/

int			find_square(int nb, int bi, int bf)
{
  int			mil;

  if (bi * bi == nb)
    return (bi);
  mil = (bi + (bf - bi) / 2);
  if (bi < bf)
    {
      if (mil * mil == nb)
	return (mil);
      else
	{
	  if (mil * mil > nb)
	    return (find_square(nb, bi, mil - 1));
	  else
	    return (find_square(nb, mil + 1, bf));
	}
    }
  return (0);
}

int			my_square_root(int nb)
{
  if (nb <= 0)
    return (0);
  return (find_square(nb, 1, 46340));
}
