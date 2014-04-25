int		my_strlen(char *str)
{
  int		occur;
  char		*curr;
  
  occur = 0;
  curr = str;
  while (*curr != '\0')
    {
      occur++;
      curr++;
    }
  return (occur);
}
