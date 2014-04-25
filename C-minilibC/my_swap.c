int		my_swap(int *a, int *b)
{
  int		t;

  t = *a;
  *a = *b;
  *b = t;
  return (1);
}
