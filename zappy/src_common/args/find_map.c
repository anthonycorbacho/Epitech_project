/*
** find_map.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a/src_server
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Mar 24 11:56:31 2010 matias1 hastaran
** Last update Fri Apr 16 17:21:20 2010 thomas1 salomon
*/

#include "server.h"
#include "args.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lmy.h"

int		find_map_x(int argc, char **argv)
{
  int		pos;

  if ((pos = find_pos(argc, argv, "-x")) == -1)
    {
      my_printf("-X already specified\n");
      return (0);
    }
  if (pos == 0)
    return (DEFAULT_X_MAP);
  else
    {
      if (!my_str_isnum(argv[pos]))
	{
	  my_printf("X has to be a number\n");
	  return (0);
	}
      return (my_atoi(argv[pos]));
    }
  return (0);
}

int		find_map_y(int argc, char **argv)
{
  int		pos;

  if ((pos = find_pos(argc, argv, "-y")) == -1)
    {
      my_printf("-Y already specified\n");
      return (0);
    }
  if (pos == 0)
    return (DEFAULT_Y_MAP);
  else
    {
      if (!my_str_isnum(argv[pos]))
	{
	  my_printf("Y has to be a number\n");
	  return (0);
	}
      return (my_atoi(argv[pos]));
    }
  return (0);
}
