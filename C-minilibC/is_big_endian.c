

int			is_big_endian(void)
{
  char			*test;
  int			*a;

  test = malloc(sizeof(*test) * 4);
  test[0] = 0;
  test[1] = 0;
  test[2] = 0;
  test[3] = 1;
  a = test;
  return (*a == 1);
}
