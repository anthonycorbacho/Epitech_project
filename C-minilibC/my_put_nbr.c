int			to_continuemyputnbr(int nb)
{
  long long		power;
  
  power = 1;
  while (nb / power != 0)
    {
      power *= 10;
    }
  power /= 10;
  while  (power != 0)
    {
      my_putchar(nb / power + 48);
      nb %= power;
      power /= 10;
    }
  return (1);
}

int			over_lmyputnbr(int nb)
{
  nb++;
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
  return (1);
}

int			my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  over_lmyputnbr(nb);
	  return (1);
	}
      nb = - nb;
    }
  else
   {
     if (nb == 0)
       {
	 my_putchar('0');
	 return (1);
       }
   }
  to_continuemyputnbr(nb);
  return (1);
}
