/*
** pose.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:50:45 2010 damien1 coppel
** Last update Sun Apr 25 16:43:26 2010 damien1 coppel
*/

#include <stdlib.h>
#include "lxsys.h"
#include "lmy.h"
#include "lstr.h"
#include "action.h"
#include "action_gr.h"
#include "definitions.h"
#include "map.h"
#include "position.h"
#include "str_utils.h"
#include "message.h"

void		pose_gr(t_client *cl, int ress_id)
{
  char		*req;
  char		*coordinate;

  coordinate = extract_coordinates_from_pos(&(cl->pos));
  req = xmalloc(my_strlen(coordinate) + 5);
  my_strcpy(req, "bct ");
  my_strcat(req, coordinate);
  free(coordinate);
  send_to_graph(player_drop_ressource_gr(cl, ress_id));
  send_to_graph(player_inventaire_gr(cl));
  send_to_graph(map_case_content_gr(req));
  free(req);
}

/*
** Takes on map cell one unit of ressources [food / rocks]
*/
int		put_rock(char *request, t_client *cl, t_map_elt *map_elt)
{
  int		id_rocks;

  id_rocks = 0;
  while (id_rocks < NB_ROCKS)
    {
      if (my_strcmp(rocks_names[id_rocks], request) == 0)
	{
	  if (cl->rocks[id_rocks] > 0)
	    {
	      cl->rocks[id_rocks]--;
	      map_elt->rocks[id_rocks]++;
	      return (id_rocks);
	    }
	}
      id_rocks++;
    }
  return (-1);
}

char		*pose(t_client *cl, t_request *req)
{
  t_map_elt	*map_elt;
  char		**request;
  int		put;

  if ((request = my_str_sep(req->request, " ")) && request[1])
    {
      del_bn(request[1]);
      map_elt = get_cell(cl->pos.x, cl->pos.y);
      if (my_strcmp(request[1], "nourriture") == 0)
	{
	  cl->life--;
	  map_elt->food++;
	  pose_gr(cl, 0);
	  free(request);
	  return (my_strdup(OK));
	}
      else if ((put = put_rock(request[1], cl, map_elt)) != -1)
	{
	  pose_gr(cl, put + 1);
	  free(request);
	  return (my_strdup(OK));
	}
    }
  free(request);
  return (my_strdup(KO));
}
