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

int			my_power(int nb, int p)
{
  int			i;
  int			ret;
  
  i = 0;
  ret = 1;
  while (i < p)
    {
      ret *= nb;
      i += 1;
    }
  return (ret);
}

int			get_signe(char *str)
{
  int			signe;
  char			*curr;
  
  curr = str;
  signe = 1;
  while (*curr == 43 | *curr == 45)
    {
      if (*curr == 45)
	{
	  signe *= - 1;
	}
      curr++;
    }
  return (signe);
}

char			*get_nb_digits(char *str, int *occur)
{
  char			*ret;
  
  *occur = 0;
  while (*str == 43 | *str == 45)
    {
      str++;
    }
  ret = str;
  while (*str > 47 & *str < 58)
    {
      (*occur)++;
      str++;
    }
  (*occur)--;
  return (ret);
}

int			my_getnbr(char *str)
{
  int		signe;
  int		number;
  int		pm;
  char		*curr;
  
  signe = get_signe(str);
  str = get_nb_digits(str, &pm);
  number = 0;
   while (pm >= 0)
    {
     if (*str > 47 & *str < 58)
	{
	  number += (*str - 48) * my_power(10, pm);
	}
     else
	{
	  return (number * signe);
	}
      str++;
      pm--;
    }
  return (number * signe);
}
