/*
** check_case.c for client in /home/tom/zappy_2012s_coppel_a
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** 
** Started on  Thu Apr 15 16:22:14 2010 thomas1 salomon
** Last update Sun Apr 25 17:27:00 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"
#include "str_utils.h"
#include "case_is_empty.h"

int		check_error(char **tabstr, int pos, char *s)
{
  if (!tabstr)
    {
      free(s);
      return (-1);
    }
  if (!tabstr[pos])
    {
      xfree_n(tabstr, s);
      return (-1);
    }
  return (1);
}

char		**do_str_sep(char **tabstr, char *s, int pos)
{
  char		**strtab;

  if (pos > 0)
    {
      free(s);
      s = tabstr[pos];
      strtab = my_str_sep(s + 1, " ");
      free(tabstr);
      return (strtab);
    }
  else
    strtab = my_str_sep(s, " ");
  free(tabstr);
  return (strtab);
}

int		check_case(char *cmd, char *to_find, int pos)
{
  char		*s;
  char		**tabstr;
  int		i;

  i = 0;
  s = del_bn_2(my_strdup(cmd));
  if (s[1] == ',')
    {
      free(s);
      return (0);
    }
  tabstr = my_str_sep(s + 1, ",");
  if (check_error(tabstr, pos, s) == -1 && pos > 0)
    return (-1);
  if (check_error(tabstr, pos, s) == 0 && pos > 0)
    return (0);
  tabstr = do_str_sep(tabstr, s, pos);
  while (tabstr && tabstr[i])
    if (my_strcmp(tabstr[i++], to_find) == 0)
      {
	xfree_n(tabstr, s, (void *) -1);
	return (1);
      }
  xfree_n(tabstr, s, (void *) -1);
  return (0);
}

int		check_inventaire(char *cmd, char *to_find, int nbr)
{
  char		*s;
  char		**tabstr;
  int		i;
  int		nb;
  char		**params;

  if (nbr == 0)
    return (1);
  i = 0;
  s = del_bn_2(my_strdup(cmd));
  tabstr = my_str_sep(s + 1, ",");
  if (tabstr)
    while (tabstr[i])
      {
	params = my_str_sep(tabstr[i], " ");
	nb = my_atoi(params[1]);
	if (my_strcmp(tabstr[i++], to_find) == 0 && nb >= nbr)
	  {
	    xfree_n(tabstr, params, s,(void *) -1);
	    return (1);
	  }
	free(params);
      }
  xfree_n(tabstr, s, (void *) -1);
  return (0);
}

int		get_inventaire_nbr(char *cmd, char *to_find)
{
  char		*s;
  char		**tabstr;
  int		i;
  int		nb;
  char		**params;

  i = 0;
  s = del_bn_2(my_strdup(cmd));
  params = NULL;
  tabstr = my_str_sep(s + 1, ",");
  while (tabstr[i] && my_strcmp(tabstr[i], to_find) != 0)
    {
      params = my_str_sep(tabstr[i], " ");
      nb = my_atoi(params[1]);
      if (my_strcmp(tabstr[i++], to_find) == 0)
	{
      	  xfree_n(params, tabstr, s, (void *) -1);
	  return (nb);
	}
      free(params);
    }
  xfree_n(tabstr, s, (void *) -1);
  return (0);
}
