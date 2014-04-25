int			my_str_isupper(char *str)
{
   while (*str)
    {
      if (!((*str > 64) && (*str < 91)))
	return (0);
      ++str;
    }
   return (1);
}
