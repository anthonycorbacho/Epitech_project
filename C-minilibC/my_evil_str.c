int			my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
  return (1);
}

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

int			my_swap_char(char *a, char *b)
{
  char			t;

  t = *a;
  *a = *b;
  *b = t;
  return (1);
}

char			*my_evil_str(char *str)
{
  int			lenc;
  int			i;

  lenc = my_strlen(str);
  i = 0;
  while(i < lenc / 2)
    {
      my_swap_char(str + i, str + lenc - i - 1);
      i++;
    }
  return (str);
}
