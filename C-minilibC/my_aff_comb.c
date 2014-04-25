int		put_3d(char i, char j, char k)
{
  my_putchar(i);
  my_putchar(j);
  my_putchar(k);
  if (!((i == '7') & (j == '8') & (k == '9')))
    {
      my_putchar(',');
      my_putchar(' ');
    }
  return (1);
}

int		my_aff_comb()
{
  char		i;
  char		j;
  char		k;

  i = '0';
  while (i <= '9')
    {
      j = i + 1;
      while (j <= '9')
        {
          k = j + 1;
          while (k <= '9')
            {
              put_3d(i, j, k);
              k++;
            }
          j++;
        }
      i++;
    }
  return (1);
}
