void			my_char_swapping (char **c, char **c1)
{
  char			*t;

  t = *c;
  *c = *c1;
  *c1 = t;
}

void			my_sort_string_table(char **tab, int size)
{
  int			i;
  int			ordered;
  char			**c1;
  int			j;

  i = 0;
  ordered = 0;
  while ((i < size) & !ordered)
    {
      c1 = tab;
      j = 0;
      ordered = 1;
      while (c1 - tab < size - 1)
        {
          if (my_strcmp(*c1, *(c1 + 1)) > 0)
            {
              ordered = 0;
              my_char_swapping(c1, c1 + 1);
            }
          c1++;
        }
      i++;
    }
}

int			main (int argc, char **argv)
{
  int			i;
  
  my_sort_string_table(argv, argc);
  i = 0;
  while (i++ < argc)
    {
      my_putstr(argv[i - 1]);
      my_putchar('\n');
    }
}
