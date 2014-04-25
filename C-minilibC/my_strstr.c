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

char			*my_strstr(char *str, char *to_find)
{
  int			len;
  int			lens;
  int			offset;
  int			i;

  if (!to_find)
    return (str);
  len = my_strlen(str);
  lens = my_strlen(to_find);
  offset = 0;
  while (offset <= len - lens)
    {
      i = 0;
      while (i < lens && *(str + i + offset) == *(to_find + i))
	++i;
      if (i == lens)
	return (str + offset);
      ++offset;
    }
  return (0);
}
