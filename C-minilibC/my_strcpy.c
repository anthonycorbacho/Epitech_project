char			*my_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while (*(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  *(dest + i) = *(src + i);
  return (dest);
}
