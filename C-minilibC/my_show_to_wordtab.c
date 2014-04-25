int     my_show_to_wordtab(char **tab)
{
  while (my_strcmp(*tab, "") != 0)
    {
      my_putstr(*tab);
      my_putchar('\n');
      tab++;
    }
  return (1);
}
