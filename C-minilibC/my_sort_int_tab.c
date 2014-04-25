int			my_swap(int *a, int *b)
{
  int			t;

  t = *a;
  *a = *b;
  *b = t;
  return (1);
}

void			my_sort_int_tab(int *tab, int size)
{
  int			i;
  int			ordered;
  int			*c1;
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
	  if (*c1 > *(c1 + 1))
	    {
	      ordered = 0;
	      my_swap(c1, c1 + 1);
	    }
	  c1++;
	}
      i++;
    }
}
