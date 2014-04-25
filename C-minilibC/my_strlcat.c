int			my_strlcat(char *str1, char *str2, int n)
{
  int			tlen;
  int			done;

  tlen = 0;
  --n;
  while (*str1)
    {
      ++str1;
      --n;
      ++tlen;
    }
  if (n < 0)
    return (tlen);
  while (*str2)
    {
      if (n > 0)
	*(str1) = *(str2);
      if (n == 0)
	*(str1) = 0;
      ++tlen;
      n--;
      ++str1;
      ++str2;
    }
  return (tlen);
}
