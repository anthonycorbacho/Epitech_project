/*
** my_is_prime.c for primes in /home/lornac_a/work/Day5
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sun Oct 11 13:32:13 2009 mathieu1 lornac
** Last update Sun Oct 11 21:24:57 2009 mathieu1 lornac
*/

int			find_rounded_square(int nb, int bi, int bf)
{
 int			mil;

  if (bi * bi == nb)
    return (bi);
  mil = bi + (bf - bi) / 2;
  if (bi <= bf)
    {
      if (mil * mil == nb)
        return (mil);
      else
        {
          if (mil * mil < nb)
	    {
	      if ((mil + 1.0) * (mil + 1.0) > nb)
		return (mil);
	      else
		return (find_rounded_square(nb, mil + 1, bf));
	    }
	  else
	    return (find_rounded_square(nb, bi, mil - 1));
	}
    }
  else
    return (0);
}

int			my_rounded_square_root(int nb)
{
  if (nb < 0)
    return (0);
  return (find_rounded_square(nb, 0, 46340));
}

int			eratosthene(int nb, int *primes)
{
  int			b_max;
  int			i;
  int			offset;

  i = 0;
  b_max = my_rounded_square_root(nb);
  while (*(primes + i) <= b_max)
    {
      if (*(primes + i) == 0)
	{
	  offset = 1;
	  while (!eratosthene(*(primes + i - 1) + offset, primes))
	    ++offset;
	  *(primes + i) = *(primes + i - 1) + offset;
	  --i;
	}
      else
	{
	  if (nb % *(primes + i) == 0)
	    return (0);
	}
      ++i;
    }
   return (1);
}

int			my_is_prime(int nombre)
{
  int			i;
  int			primes[1000000];

  if (nombre < 2)
    return (0);
  i = 0;
  while (++i < 1000000)
    primes[i] = 0;
  primes[0] = 2;
  return (eratosthene(nombre, primes));
}
