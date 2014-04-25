/*
** inventaire.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:50:32 2010 damien1 coppel
** Last update Sat Apr 24 14:02:43 2010 damien1 coppel
*/

#include "action.h"
#include "definitions.h"
#include "lxsys.h"
#include "lmy.h"
#include "lstr.h"
#include "lmy_printf.h"

char		*inventaire(t_client *cl,
			    __attribute__((unused))t_request *req)
{
  char		*nbr_as_str;
  char		*msg;
  int		r;

  msg = xmalloc(1024 * sizeof(char));
  msg[0] = 0;
  my_strcat(msg, "{nourriture ");
  nbr_as_str = my_sprintf(cl->life);
  my_strcat(msg, nbr_as_str);
  free(nbr_as_str);
  my_strcat(msg, ",");
  r = -1;
  while (++r < NB_ROCKS)
    {
      my_strcat(msg, rocks_names[r]);
      my_strcat(msg, " ");
      nbr_as_str = my_sprintf(cl->rocks[r]);
      my_strcat(msg, nbr_as_str);
      free(nbr_as_str);
      if (r != (NB_ROCKS - 1))
	my_strcat(msg, ",");
    }
  my_strcat(msg, "}");
  return (my_strcat(msg, "\n"));
}
