/*
** get_params.c for client in /home/tom/zappy_2012s_coppel_a
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** 
** Started on  Fri Apr 16 17:06:44 2010 thomas1 salomon
** Last update Sun Apr 25 17:30:07 2010 thomas1 salomon
*/

#include "client.h"
#include "definitions.h"
#include "args.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lmy.h"

int		get_team_name(int argc, char **argv, t_player *p)
{
  int		pos;

  if ((pos = find_pos(argc, argv, "-n")) <= 0)
    {
      my_printf("-n absent or specified twice\n");
      return (0);
    }
  else if (argv[pos + 1] != NULL && argv[pos + 1][0] != '-')
    {
      my_printf("Only specify one team name\n");
      return (0);
    }
  p->team_name = my_strdup(argv[pos]);
  return (1);
}

int		get_host(int argc, char **argv, t_player *p)
{
  int		pos;

  if ((pos = find_pos(argc, argv, "-h")) == -1)
    {
      my_printf("-h already specified\n");
      return (0);
    }
  if (pos == 0)
    {
      p->host_name = my_strdup(DEFAULT_HOST);
      return (1);
    }
  else
    {
      p->host_name = my_strdup(argv[pos]);
      return (1);
    }
  return (0);
}

int		get_params(int argc, char **argv, t_player *p)
{
  if (get_host(argc, argv, p) == 0)
    return (0);
  if (get_team_name(argc, argv, p) == 0)
    return (0);
  if ((p->port = find_port(argc, argv)) == 0)
    return (0);
  return (1);
}
