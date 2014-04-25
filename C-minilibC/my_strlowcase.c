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

char			*my_strlowcase(char *str)
{
  char			*ret;

  ret = str;
  while (*str)
    {
      if (*str > 64 && *str < 91)
	*str += 32;
      ++str;
    }
  return (ret);
}
