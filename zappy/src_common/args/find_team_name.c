/*
** find_time_name.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a/src_server
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Mar 24 13:11:14 2010 matias1 hastaran
** Last update Fri Apr 16 17:51:04 2010 thomas1 salomon
*/

#include "lmy_printf.h"
#include "server.h"
#include "args.h"
#include "lstr.h"
#include "lmy.h"
#include "lxsys.h"

void		get_team_names(int i, int ac, char **av, t_zappy_args *opt)
{
  int		n;

  n = 0;
  while ((i + n < ac) && (av[i + n][0] != '-'))
    n++;
  opt->nb_teams = n;
  opt->team_names = xmalloc(sizeof(*opt->team_names) * n);
  n = 0;
  while ((i + n < ac) && (av[i + n][0] != '-'))
    {
      opt->team_names[n] = av[i + n];
      n++;
    }
}

int		find_team_name(int argc, char **argv, t_zappy_args *opt)
{
  int		pos;

  if ((pos = find_pos(argc, argv, "-n")) <= 0)
    {
      my_printf("-n absent or specified twice\n");
      return (0);
    }
  get_team_names(pos, argc, argv, opt);
  return (1);
}
