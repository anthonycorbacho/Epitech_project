/*
** map_gr_2.c for zappy in /home/damien/work_local/zappy/src_server
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Fri Apr 16 13:36:41 2010 damien1 coppel
** Last update Sat Apr 24 14:03:11 2010 damien1 coppel
*/

#include "lstr.h"
#include "lxsys.h"

#include "server.h"
#include "action_gr.h"
#include "map.h"
#include "position.h"
#include "str_utils.h"
#include "map.h"

char	*map_size_gr()
{
  char	*to_send;
  char	*sx;
  char	*sy;

  sx = my_sprintf(map_size.x);
  sy = my_sprintf(map_size.y);
  to_send = malloc(my_strlen(sx) + my_strlen(sy) + 7);
  my_strcpy(to_send, "msz ");
  my_strcat(to_send, sx);
  my_strcat(to_send, " ");
  my_strcat(to_send, sy);
  my_strcat(to_send, "\n");
  free(sx);
  free(sy);
  return (to_send);
}
