/*
** find_time.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a/src_server
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Mar 24 13:06:45 2010 matias1 hastaran
** Last update Fri Apr 16 17:16:04 2010 thomas1 salomon
*/

#include "server.h"
#include "definitions.h"
#include "args.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lmy.h"

int		find_time(int argc, char **argv)
{
  int		pos;
  int		time;

  if ((pos = find_pos(argc, argv, "-t")) == -1)
    {
      my_printf("-t already specified\n");
      return (0);
    }
  if (pos == 0)
    return (TIME_UNIT);
  else
    {
      if (!my_str_isnum(argv[pos]))
	{
	  my_printf("T has to be a number\n");
	  return (0);
	}
      time = my_atoi(argv[pos]);
      if (!time)
	time = TIME_UNIT;
      return (time);
    }
  return (0);
}
