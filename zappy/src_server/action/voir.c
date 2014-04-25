/*
** voir.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:51:19 2010 damien1 coppel
** Last update Thu Mar 25 15:14:41 2010 mathieu1 lornac
*/

#include "action.h"
#include "vision.h"

char	*voir(t_client *cl, __attribute__((unused))t_request *req)
{
  return (get_view(cl));
}
