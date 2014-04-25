/*
** player_init.c for zappy client in /home/tom/zappy_2012s_coppel_a
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** 
** Started on  Tue Apr 20 11:43:09 2010 thomas1 salomon
** Last update Tue Apr 20 17:11:53 2010 matias1 hastaran
*/

#include <time.h>
#include <stdlib.h>

#include "lxsys.h"
#include "client.h"
/*
** Structure initialisation
*/

int			player_init(t_player *p)
{
  struct timeval	tv;

  xgettimeofday(&tv, 0);
  p->id = tv.tv_usec;
  p->level = 1;
  p->food_flag = 0;
  p->jewel_flag = 0;
  p->move_flag = -1;
  p->do_incant = 0;
  p->send_flag = 0;
  p->target_id = 0;
  p->jewel_name = NULL;
  p->end_flag = 1;
  return (0);
}
