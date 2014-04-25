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

char			*my_strcapitalize(char *str)
{
  int			to_cap;
  char			*s;

  s = str;
  to_cap = 1;
  while (*s)
    {
      if ((*s > 64 && *s < 91) || (*s > 96 && *s < 123) || (*s > 47 && *s < 58))
	{
	  if (to_cap && (*s > 96 && *s < 123))
	    *s -= 32;
	  else
	    if ((!to_cap) && (*s >64 && *s < 91))
	      *s += 32;
	  to_cap = 0;
	}
      else
	to_cap = 1;
      ++s;
    }
  return (str);
}
