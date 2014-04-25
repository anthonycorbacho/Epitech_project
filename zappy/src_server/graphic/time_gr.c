/*
** time_gr.c for zappy in /home/damien/work_local/za/src_server/graphic/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 16:06:54 2010 damien1 coppel
** Last update Sat Apr 24 14:03:31 2010 damien1 coppel
*/

#include "lstr.h"
#include "lxsys.h"

#include "server.h"
#include "action_gr.h"

char	*time_ask_unit_gr()
{
  char	*to_send;
  char	*t;

  t = my_sprintf(vars->latence);
  to_send = xmalloc(sizeof(*to_send) * (my_strlen(t) + 6));
  my_strcpy(to_send, "sgt ");
  my_strcat(to_send, t);
  my_strcat(to_send, "\n");
  free(t);
  return (to_send);
}

char	*time_modif_unit_gr(int time_unit)
{
  vars->latence = time_unit;
  return (time_ask_unit_gr());
}
