/*
** time_manipulation.c for zappy in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Mon Apr 12 13:25:58 2010 mathieu1 lornac
** Last update Tue Apr 13 19:14:29 2010 mathieu1 lornac
*/

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "server.h"
#include "process_clients.h"
#include "definitions.h"
#include "request.h"
#include "str_utils.h"
#include "time_management.h"
#include "action_gr.h"
#include "action.h"
#include "map.h"
#include "incantation.h"

/*
** Add time_to_add to the struct tv
*/
void			add_time(struct timeval *tv, int time_to_add)
{
  int			time_to_add_ms;
  int			time_to_add_s;

  time_to_add_ms = time_to_add / vars->latence;
  tv->tv_usec += time_to_add_ms;
  time_to_add_s = tv->tv_usec / 1000000;
  tv->tv_sec += time_to_add_s;
  tv->tv_usec = tv->tv_usec % 1000000;
}

/*
** Return true if the time is reach
*/
int			time_is_reach(struct timeval *time)
{
  struct timeval	tv;

  xgettimeofday(&tv, 0);
  if ((time->tv_sec < tv.tv_sec) ||
      ((time->tv_sec == tv.tv_sec) &&
       (time->tv_usec <= tv.tv_usec)))
    return (1);
  return (0);
}
