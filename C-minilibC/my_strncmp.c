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

int			my_strncmp(char *s1, char *s2, int n)
{
  while (n > 0 && *s1)
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      ++s1;
      ++s2;
      --n;
    }
  return (0);
}
