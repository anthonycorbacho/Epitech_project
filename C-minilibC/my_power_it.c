/*
** my_power_it.c for my_power_it in /home/lornac_a/work/Day5
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Oct  9 09:10:28 2009 mathieu1 lornac
** Last update Sun Oct 11 21:37:56 2009 mathieu1 lornac
*/

int			signe(int nb){
  return (nb > 0);
}

int			calculate(int nb, int power)
{
  int			orig_value;

  orig_value = nb;
  while (power > 1)
    {
      if (orig_value < 0 && signe(nb) == signe(nb * orig_value))
	return (0);
      else
        {
          if (orig_value > 0 && !signe(nb * orig_value))
	    return (0);
        }
      nb = nb * orig_value;
      power--;
    }
  return (nb);
}

int			my_power_it(int nb, int power){
  if (power < 0)
    return (0);
  else
    {
      if (power == 0)
	return (1);
    }
  return (calculate(nb, power));
}
