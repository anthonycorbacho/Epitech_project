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

void			my_putnbr_basemodif(int nbr, char *base, int nbd)
{
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


void			my_char_printable (char str)
{
  if ((str < 32) || (str > 126))
    my_putchar('.');
  else
    my_putchar(str);
}

char			*showline(char *line, char* orig)
{
  char			*cursor;
  int			i;

  i = 0;
  cursor = line;
  my_putnbr_basemodif((int) line - (int) orig, "0123456789abcdef", 8);
  my_putchar(':');
  my_putchar(' ');
  while (i++ < 16)
    {
      if (*line)
	my_putnbr_basemodif(*(line++), "0123456789abcdef", 2);
      else
	{
	  my_putchar(' ');
	  my_putchar(' ');
	}
      if (i % 2 == 0)
	my_putchar(' ');
    }
    while (cursor != line)
    my_char_printable(*(cursor++));
    my_putchar('\n');
    return (line);
}

int			my_showmem(char *str, int size)
{
  char			*curr;

  curr = str;
  while (*curr)
    curr = showline(curr, str);
  return (0);
}
