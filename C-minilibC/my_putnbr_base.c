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

int			my_putnbr_base(int nbr, char *base){

  int			base_v;
  int			i;
  long long		power;
  long long		nb;

  nb = nbr;
  if (nb < 0)
    {
      nb = - nb;
      my_putchar('-');
    }
  power = 1;
  base_v = my_strlen(base);
  while (nb / power != 0)
    power *= base_v;
  power /= base_v;
  while (power != 0){
    i = 0;
    while ((i < base_v) && (power * i <= nb))
      ++i;
    --i;
    my_putchar(base[i]);
    nb %= power;
    power /= base_v;
  }
  return (1);
}
