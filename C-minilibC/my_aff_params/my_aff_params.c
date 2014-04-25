int			main (int argc, char **argv)
{
  int			i;

  i = 0;
  while (i++ < argc)
    {
      my_putstr(argv[i - 1]);
      my_putchar('\n');
    }
}
