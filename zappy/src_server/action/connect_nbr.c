/*
** connect_nbr.c for zappy in /home/damien/work_local/my_zappy/
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:49:00 2010 damien1 coppel
** Last update Fri Apr 16 15:18:00 2010 damien1 coppel
*/

#include "action.h"
#include "lstr.h"
#include "lmy_printf.h"
#include "lxsys.h"

char	*connect_nbr(t_client *cl, t_request *req)
{
  char	*ret;

  my_printf("Player on cell: X,Y: %d,%d | orient: %d | level: %d\n",
	    cl->pos.x, cl->pos.y, cl->orientation, cl->level);
  req = req;
  ret = xmalloc(sizeof(*ret) * (my_strlen(cl->team_name) + 2));
  my_strcpy(ret, cl->team_name);
  my_strcat(ret, "\n");
  return (ret);
}
