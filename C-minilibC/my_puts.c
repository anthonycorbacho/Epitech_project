int my_putchar(char c)
{
  write(1,&c,1);
}

int		my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
  return (1);
}

int		aff_lim(int nb)
{
  nb++;
  my_putchar('-');
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

int		my_put_nbr(int nb)
{
  long long	len;

  len = 10;
  if ( nb == - 2147483648)
    {
      aff_lim(1);
      return (1);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
    }
  while (nb / len > 0)
    {
      len *= 10;
    }
  len /= 10;
  while ( len > 0)
    {
      my_putchar(nb / len + 48);
      nb %= len;
      len /= 10;
    }
  return (1);
}