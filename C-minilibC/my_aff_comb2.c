int		my_aff_comb2()
{
  int		nb1;
  int		nb2;

  nb1 = 0;
  while (nb1 < 99)
    {
      nb2 = nb1 + 1;
      while (nb2 <= 99)
        {
          my_putchar(nb1 / 10 + 48);
          my_putchar(nb1 % 10 + 48);
          my_putchar(' ');
          my_putchar(nb2 / 10 + 48);
          my_putchar(nb2 % 10 + 48);
          if (!((nb1 == 98) & (nb2 == 99)))
            {
              my_putchar(',');
              my_putchar(' ');
            }
          nb2++;
        }
      nb1++;
    }
  return (1);
}
