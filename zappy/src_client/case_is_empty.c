/*
** check_case.c for client in /home/tom/zappy_2012s_coppel_a
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** 
** Started on  Thu Apr 15 16:22:14 2010 thomas1 salomon
** Last update Sun Apr 25 17:23:57 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"
#include "str_utils.h"

#include "definitions.h"
#include "check_case.h"
#include "gnl_socket.h"
#include "gnl_parsing.h"
#include "case_is_empty.h"
#include "ip_protocol.h"
#include "check_case.h"
#include "client_movement.h"

void		free_check_strtab(char **str1, char **str2)
{
  free(str1);
  free(str2);
}

int		case_is_empty(char *cmd)
{
  char		*s;
  char		**tabstr;
  int		i;
  int		j;

  i = 0;
  j = 0;
  s = del_bn_2(my_strdup(cmd + 1));
  tabstr = my_str_sep(s, ",");
  tabstr = do_str_sep(tabstr, s, 0);
  while (tabstr && tabstr[i])
    {
      while (j < NB_ROCKS)
	if (my_strcmp(tabstr[i], rocks_names[j++]) == 0
	    || my_strcmp(tabstr[i], "nourriture") == 0)
	  {
	    xfree_n(tabstr, s, (void *) -1);
	    return (0);
	  }
      i++;
      j = 0;
    }
  xfree_n(tabstr, s, (void *) -1);
  return (1);
}

int			empty_case(t_player *p)
{
  char			**tab;
  char			*s;
  char			*tmp;
  int			i;

  i = -1;
  my_send(p->server_socket, "voir\n");
  s = gnl_parsing(p);
  tab = my_str_sep(del_bn_2(s + 1), ",");
  tab = my_str_sep(tab[0], " ");
  while (tab[++i])
    {
      if (my_strcmp(tab[i], "joueur") != 0)
	{
	  my_send(p->server_socket, "prend ");
	  my_send(p->server_socket, tab[i]);
	  my_send(p->server_socket, "\n");
	  tmp = gnl_parsing(p);
	  free(tmp);
	}
    }
  xfree_n(s, tab, (void *) -1);
  return (1);
}
