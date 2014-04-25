char			*my_strcat(char *str1, char *str2)
{
  char			*curr;

  curr = str1;
  while (*curr)
    ++curr;
  while (*str2)
    *(curr++) = *(str2++);
  *(curr) = *(str2);
  return (str1);
}
