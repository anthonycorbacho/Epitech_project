/*
** args.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a/src_server
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Mar 24 10:15:52 2010 matias1 hastaran
** Last update Fri Apr 16 16:46:56 2010 thomas1 salomon
*/

#include "lmy_printf.h"
#include "args.h"
#include "lstr.h"
#include "server.h"
#include "map.h"

int		find_pos(int argc, char **argv, char *value)
{
  int		i;
  int		pos;
  int		nbr;

  i = 1;
  pos = 0;
  nbr = 0;
  while(i < argc)
    { 
      if (my_strcmp(value, argv[i]) == 0)
	{
	  pos = i;
	  nbr++;
	}
      i++;
    }
  if (nbr == 0)
    return (0);
  if (nbr > 1)
    return (-1);
  return (pos + 1);
}

void		print_usage()
{
  my_putstr("\033[31m");
  my_putstr("Error: Missing or wrong arguments\n");
  my_putstr("\033[39m");
  my_putstr("Usage:\n");
  my_putstr("./serveur -p port -n team1 team2...\n[-x world's width]");
  my_putstr(" [-y world's height]\n[-c players by team]");
  my_putstr(" [-t time]\n");
}

int		verif_args_validity(char *args, char arg)
{
  while(*args)
    {
      if (*args == arg)
	return (1);
      args++;
    }
  return (0);
}

int		checks_args(int argc, char **argv, char *params)
{
  int	i;

  i = 1;
  while (i < argc)
    {
      if ((argv[i][0] == '-') && verif_args_validity(params, argv[i][1]))
	{
	  i++;
	  if (i == argc)
	    return (0);
	  if (argv[i][0] == '-')
	    return (0);
	  if (argv[i - 1][1] == 'n')
	    {
	      while ((i < argc) && (argv[i][0] != '-'))
		i++;
	      if (i == argc)
		return (1);
	    }
	  else
	    i++;
	}
      else
	return (0);
    }
  return (1);
}

int		find_opt_values(int argc, char **argv, t_zappy_args *opt)
{
  my_putstr("\033[31m");
  if ((opt->team_max_size = find_guest(argc, argv)) < 0)
    return (0);
  if ((opt->port = find_port(argc, argv)) == 0)
    return (0);
  if ((map_size.x = find_map_x(argc, argv)) == 0)
    return (0);
  if ((map_size.y = find_map_y(argc, argv)) == 0)
    return (0);
  if ((opt->time = find_time(argc, argv)) == 0)
    return (0);
  if (find_team_name(argc, argv, opt) == 0)
    return (0);
  my_putstr("\033[39m");
  return (1);
}
