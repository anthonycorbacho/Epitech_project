int			my_str_islower(char *str)
{
   while (*str)
    {
      if (!((*str > 96) && (*str < 123)))
	return (0);
      ++str;
    }
   return (1);
}
