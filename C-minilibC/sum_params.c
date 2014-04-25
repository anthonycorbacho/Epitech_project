char			*sum_params(int argc, char **argv)
{
  char			*r;
  int			size;
  int			i;

  size = 0;
  i = 0;
  while (i++ < argc)
      size += my_strlen(argv[i - 1]) + 1;
  r = malloc(sizeof(*r) * size);
  i = 0;
  while (i++ < argc)
    {
      my_strcat(r, argv[i - 1]);
      if (i < argc)
	my_strcat(r, "\n");
    }
  return (r);
}
