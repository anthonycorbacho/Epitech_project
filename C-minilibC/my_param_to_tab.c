#include "my.h"

struct s_stock_par	*my_param_to_tab(int ac, char **av)
{
  struct s_stock_par	*ret;
  int			i;

  ret = malloc(sizeof(*ret) * (ac + 1));
  if (ret == 0)
    return (0);
  i = 0;
  while (i < ac)
    {
      ret[i].size_param = my_strlen(av[i]);
      ret[i].str = av[i];
      ret[i].copy = my_strdup(av[i]);
      ret[i].tab = my_str_to_wordtab(av[i]);
      ++i;
    }
  ret[ac].str = 0;
  return (ret);
}
