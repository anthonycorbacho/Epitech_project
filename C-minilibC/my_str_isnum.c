int			my_str_isnum(char *str)
{
   while (*str)
    {
      if (!(*str > 47 && *str < 58))
	return (0);
      ++str;
    }
   return (1);
}
