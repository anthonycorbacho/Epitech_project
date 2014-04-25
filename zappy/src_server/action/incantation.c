/*
** incantation.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:50:19 2010 damien1 coppel
** Last update Sat Apr 24 14:02:37 2010 damien1 coppel
*/

#include "lstr.h"
#include "lxsys.h"

#include "action.h"
#include "action_gr.h"
#include "map.h"
#include "incantation.h"
#include "position.h"
#include "win_game.h"
#include "message.h"

/*
** List the nb of players on the cell
** (doesn't count the player himself)
*/
int		get_nb_players_on_cell(t_client *cl)
{
  t_list	*cur;
  t_client	*cur_cl;
  int		found;

  found = 0;
  cur = vars->list_clients;
  while (cur)
    {
      cur_cl = cur->data;
      if (cmp_pos(&cl->pos, &cur_cl->pos) && (cl->level == cur_cl->level))
	found++;
      cur = cur->next;
    }
  return (found);
}

/*
** Returns 1 if the incantation is possible
** 0 otherwise
*/
int		incantation_possible(t_client *cl)
{
  t_incantation	incant[NB_INCANT] = INCANT_VALUES;
  int		i;
  t_map_elt	*cell;

  if (cl->level < 8)
    {
      if (get_nb_players_on_cell(cl) == incant[cl->level - 1].nbp)
	{
	  i = -1;
	  cell = get_cell(cl->pos.x, cl->pos.y);
	  while (++i < NB_ROCKS)
	    {
	      if (cell->rocks[i] != incant[cl->level - 1].rocks[i])
		return (0);
	    }
	  return (1);
	}
    }
  return (0);
}

/*
** Redistribute the rocks on the map
** Sends the cells modified to the graphic client
*/
void		redistribute_rocks(t_incantation *incant)
{
  int		i;
  t_map_elt	*cell;
  char		*req;
  char		*coordinate;
  t_pos		pos;

  req = NULL;
  i = -1;
  while (++i < NB_ROCKS)
    {
      if (incant->rocks[i])
	{
	  pos.x = rand() % map_size.x;
	  pos.y = rand() % map_size.y;
	  cell = get_cell(pos.x, pos.y);
	  cell->rocks[i] += incant->rocks[i];
	  coordinate = extract_coordinates_from_pos(&pos);
	  req = xmalloc(my_strlen(coordinate) + 5);
	  my_strcpy(req, "bct ");
	  my_strcat(req, coordinate);
	  free(coordinate);
	  send_to_graph(map_case_content_gr(req));
	  free(req);
	}
    }
}

void		incantation_ok(t_client *cl)
{
  t_map_elt	*cell;
  int		i;
  t_incantation	incant[NB_INCANT] = INCANT_VALUES;
  t_list	*cur;
  t_client	*cur_cl;

  send_to_graph(player_incantation_end_gr(cl, 1));
  cell = get_cell(cl->pos.x, cl->pos.y);
  i = -1;
  while (++i < NB_ROCKS)
    cell->rocks[i] -= incant[cl->level - 1].rocks[i];
  cur = vars->list_clients;
  while (cur)
    {
      cur_cl = ((t_client*)(cur->data));
      if (cmp_pos(&cl->pos, &cur_cl->pos))
	++cur_cl->level;
      send_to_graph(player_level_gr(cur_cl));
      cur = cur->next;
    }
  redistribute_rocks(incant + cl->level - 2);
  has_won_game(cl);
}

char		*incantation(t_client *cl,
			     __attribute__((unused))t_request *req)
{
  char		*str;
  char		*lvl;

  if (incantation_possible(cl))
    {
      incantation_ok(cl);
      lvl = my_sprintf(cl->level);
      str = xmalloc(sizeof(*str) * (18 + my_strlen(lvl)));
      my_strcpy(str, "niveau actuel : ");
      my_strcat(str, lvl);
      my_strcat(str, "\n");
      free(lvl);
    }
  else
    {
      str = my_strdup(KO);
      send_to_graph(player_incantation_end_gr(cl, 0));
    }
  return (str);
}
