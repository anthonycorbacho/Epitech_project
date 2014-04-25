int			my_strlen(char *str)
{
  int			occur;
  char			*curr;

  occur = 0;
  curr = str;
  while (*curr != '\0')
    {
      occur++;
      curr++;
    }
  return (occur);
}

void                    my_putnbr_basemodif(int nbr, char *base, int nbd)
{
  int                   base_v;
  int                   i;
  long long             power;
  long long             nb;

  nb = nbr;
  if (nb < 0)
    {
      nb = - nb;
      my_putchar('-');
    }
  power = 1;
  base_v = my_strlen(base);
  while (--nbd > 0)
    power *= base_v;
  while (power != 0){
    i = 0;
    while ((i < base_v) && (power * i <= nb))
      ++i;
    --i;
    my_putchar(base[i]);
    nb %= power;
    power /= base_v;
  }
}


int			my_char_isprintable(char str)
{
  if ((str < 32) || (str > 126))
    return (0);
  else
    return (1);
}

int			my_showstr(char *str)
{
  while (*str)
    {
      if (my_char_isprintable(*str) != 0)
	my_putchar(*str);
      else
	{
	  my_putchar('\\');
	  my_putnbr_basemodif(*str, "0123456789abcdef", 2);
	}
      ++str;
    }
  return (0);
}
