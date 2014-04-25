char			*my_strncat(char *str1, char *str2, int n)
{
  char			*curr;

  curr = str1;
  while (*curr)
    ++curr;
  while (n-- > 0 && *str2)
    *(curr++) = *(str2++);
  if (n == 0)
    ++curr;
  *(curr) = 0;
  return (str1);
}
