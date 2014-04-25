/*
** my_power_rec.c for my_power_rec in /home/lornac_a/work/Day5
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Oct  9 10:10:28 2009 mathieu1 lornac
** Last update Tue Oct 13 10:02:58 2009 mathieu1 lornac
*/

int			my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (nb == 1)
    return (1);
  if (nb == -1 && power % 2 == 0)
    return (1);
  if (nb == -1 && power % 2 == 1)
    return (-1);
  if (power > 1)
    return (nb * my_power_rec(nb, power - 1));
  else
    return (nb);
}
