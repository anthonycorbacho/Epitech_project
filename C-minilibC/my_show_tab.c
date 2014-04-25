
int			my_show_tab(struct s_stock_par *par)
{
  int i;

  i = 0;
  while ((par->str) != 0)
    {
      my_putstr(par->copy);
      my_putchar('\n');
      my_put_nbr(par->size_param);
      my_putchar('\n');
      my_show_to_wordtab(par->tab);
      ++par;
    }
}
