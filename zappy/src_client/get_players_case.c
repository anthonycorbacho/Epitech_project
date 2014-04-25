/*
** get_players_case.c for zappy
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Sat Apr 24 18:28:30 2010 pierre1 rolland
** Last update Sun Apr 25 17:30:54 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"
#include "str_utils.h"
#include "case_is_empty.h"
#include "check_case.h"

int		get_players_case(char *cmd)
{
  char		*s;
  char		**tabstr;
  int		i;
  int		cnt;

  i = 0;
  cnt = 0;
  s = del_bn_2(my_strdup(cmd));
  if (s[1] == ',')
    {
      free(s);
      return (0);
    }
  tabstr = my_str_sep(s + 1, ",");
  if (check_error(tabstr, 0, s) == -1)
    return (-1);
  if (check_error(tabstr, 0, s) == 0)
    return (0);
  tabstr = do_str_sep(tabstr, s + 1, 0);
  while (tabstr && tabstr[i])
    if (my_strcmp(tabstr[i++], "joueur") == 0)
      cnt++;
  xfree_n(tabstr, s, (void *) -1);
  return (cnt);
}
