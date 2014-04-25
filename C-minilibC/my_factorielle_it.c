/*
** my_factorielle_it.c for my_bad_facto in /home/lornac_a
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Oct  9 08:38:50 2009 mathieu1 lornac
** Last update Sat Oct 10 17:02:37 2009 mathieu1 lornac
*/

int			my_factorielle_it(int nb)
{
  int			ret;

  ret = 1;
  if (nb < 0)
      return (0);
  else
    {
      while (nb > 1 && ret > 0)
	{
	  ret *= nb;
	  nb--;
	}
      if (ret < 0)
	  return (0);
      else
	  return (ret);
    }
}
