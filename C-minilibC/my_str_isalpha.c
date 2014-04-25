int			my_str_isalpha(char *str)
{
   while (*str)
    {
      if (!((*str > 64 && *str < 91) || (*str > 96 && *str < 123)))
	return (0);
      ++str;
    }
   return (1);
}
