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

char			*my_revstr(char *str)
{
  int			i;
  int			len;
  char			c;

  len = my_strlen(str);
  i = 0;
  while (i < len / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + len - i - 1);
      *(str + len - i - 1) = c;
      ++i;
    }
  return (str);
}
