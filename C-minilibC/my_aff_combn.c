unsigned long		my_power(unsigned long nb, int p)
{
  int			i;
  unsigned long		ret;
  
  i = 0;
  ret = 1;
  while (i < p)
    {
      ret *= nb;
      i += 1;
    }
  return (ret);
}

unsigned long		generate_smallest(int n)
{
  int			i;
  unsigned long		nb;
  int			d;
  
  i = 0;
  d = 9;
  nb = 0;
  while (i < n){
    nb += (d - 9 + n) * my_power(10, i);
    d--;
    i++;
  }
  return (nb);
}

int			is_increasing(unsigned long nb, int n)
{
  int			d;

  n--;
  d = nb / my_power(10, n);
  while (nb > 9)
    {
      nb %= my_power(10, n);
      n--;
      if (nb / my_power(10, n) <= d)
	{
	  return (0);
	}
      else
	{
	  d = nb / my_power(10, n);
	}
    }
  return (1);
}

unsigned long		get_next_nb(unsigned long nb, int n)
{
  int			good;

  good = 0;
  while (!good)
    {
      nb++;
      good = is_increasing(nb, n);
      if (nb > my_power(10, n) | (nb > 123456789))
	{
	  return (- 1);
	}
    }
  return (nb);
}

int			to_continue(unsigned long nb)
{
  unsigned long		power;
  
  power = 1;
  while (nb / power != 0)
    {
      power *= 10;
    }
  while (nb != 0)
    {
      power /= 10;
      my_putchar(nb / power + 48);
      nb %= power;
    }
  return (1);
}

int			my_put_nbr(unsigned long nb)
{
  if (nb < 0)
    {
      my_putchar('-');
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
  to_continue(nb);
  return (1);
}


int			my_relay(int n, int f, int s)
{
  unsigned long		nb;

  nb = generate_smallest(n);
  while (nb != - 1)
    {
      if (f == 0)
	{
	  my_putchar('0');
	}
      my_put_nbr(nb);
      nb = get_next_nb(nb, n);
      if ( (nb != - 1 | f == 0) & (s == 0) )
        {
	  my_putchar(',');
          my_putchar(' ');
        }
    }
  return (1);
}

int			my_aff_combn(int n)
{
  if (n <= 0 | n > 10)
    {
      return (0);
    }
  if (n != 10)
    {
      my_relay(n - 1, 0, 0);
      my_relay(n, 1, 0);
    }
  else
    {
      my_relay(n - 1, 0, 1);
    }
  return (1);
}
