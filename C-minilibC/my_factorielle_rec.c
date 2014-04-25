/*
** my_factorielle_rec.c for my_facto in /home/lornac_a/work/Day5
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Oct  9 08:51:42 2009 mathieu1 lornac
** Last update Sat Oct 10 17:04:11 2009 mathieu1 lornac
*/

int			my_factorielle_rec(int nb)
{
  if (nb < 0)
      return (0);
  else
    {
      if (nb == 0)
	  return (1);
      else
	{
	  if (nb * (nb - 1) < 0)
	      return (0);
	  else
	    return (nb * my_factorielle_rec(nb - 1));
	}
    }
}
