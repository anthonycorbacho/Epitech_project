/*
** team_gr.c for zappy in /home/damien/work_local/z/src_server/graphic/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 16:06:39 2010 damien1 coppel
** Last update Sat Apr 24 14:03:28 2010 damien1 coppel
*/

#include "lstr.h"
#include "lxsys.h"
#include "action_gr.h"
#include "server.h"
#include "str_utils.h"

void		strcat_teamname(char *to_send, t_team **cur)
{
  my_strcat(to_send, "tna ");
  my_strcat(to_send, (*cur)->team_name);
  my_strcat(to_send, "\n");
}

char		*team_name_gr()
{
  t_team	**cur;
  char		*to_send;
  int		len;

  len = 0;
  cur = vars->team_list;
  while (*cur)
    {
      if ((*cur)->team_name)
	len += 5 + my_strlen((*cur)->team_name);
      ++cur;
    }
  cur = vars->team_list;
  to_send = xmalloc(len + 1);
  *to_send = 0;
  while (*cur)
    {
      if ((*cur)->team_name)
	strcat_teamname(to_send, cur);
      ++cur;
    }
  return (to_send);
}
