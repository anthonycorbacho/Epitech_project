/*
** find_guest.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a/src_server
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Mar 24 13:03:41 2010 matias1 hastaran
** Last update Fri Apr  9 17:28:54 2010 mathieu1 lornac
*/

#include "lmy_printf.h"
#include "args.h"
#include "lstr.h"
#include "lmy.h"
#include "server.h"

int		find_guest(int argc, char **argv)
{
  int		pos;

  if ((pos = find_pos(argc, argv, "-c")) == -1)
    {
      my_printf("-C already specified\n");
      return (-1);
    }
  if (pos == argc)
    return (-1);
  if (!pos)
    return (DEFAULT_TEAM_SIZE);
  if (!my_str_isnum(argv[pos]))
    {
      my_printf("C has to be a number\n");
      return (-1);
    }
  return (my_atoi(argv[pos]));
}
