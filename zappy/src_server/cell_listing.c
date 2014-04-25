/*
** cell_listing.c for cell in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Thu Mar 25 13:48:35 2010 mathieu1 lornac
** Last update Sat Apr 24 14:01:34 2010 damien1 coppel
*/

#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "map.h"
#include "server.h"
#include "process_clients.h"
#include "position.h"

/*
** Concatenates the players to the buffer
*/
int		get_players_on_cell(t_pos *cell, char *buffer, int p_id,
				    int doit)
{
  t_list	*cl;
  int		ret;

  ret = 0;
  cl = vars->list_clients;
  while (cl)
    {
      if (cmp_pos(cell, &(((t_client *)cl->data)->pos)))
	{
	  if (((t_client *)cl->data)->id != p_id)
	    {
	      if (doit)
		my_strcat(buffer, "joueur ");
	      ret += 7;
	    }
	}
      cl = cl->next;
    }
  return (ret);
}

/*
** List the rocks contained in the cell
*/
int		get_cell_rocks(t_map_elt *cell, char *buffer, int found,
			       int doit)
{
  uchar		a;
  int		i;
  int		ret;

  ret = 0;
  i = -1;
  while (++i < NB_ROCKS)
    {
      a = cell->rocks[i];
      while (a--)
	{
	  if ((a != cell->rocks[i] - 1) || found)
	    {
	      if (doit)
		my_strcat(buffer, " ");
	      ret += 1;
	    }
	  if (doit)
	    my_strcat(buffer, rocks_names[i]);
	  ret += my_strlen(rocks_names[i]);
	  found = 1;
	}
    }
  return (ret);
}

/*
** Returns a string describing the cell content
** String format: nourriture nourriture linemate
*/
int		get_cell_content(t_pos *pos, char *buffer, int p_id, int doit)
{
  t_map_elt	*cell;
  uchar		a;
  int		found;
  t_pos		real_coords;
  int		ret;

  tranlate_coords(pos, &real_coords);
  ret = get_players_on_cell(&real_coords, buffer, p_id, doit);
  cell = get_cell(real_coords.x, real_coords.y);
  a = cell->food;
  found = 0;
  while (a--)
    {
      if (a != cell->food - 1)
	{
	  if (doit)
	    my_strcat(buffer, " ");
	  ret++;
	}
      if (doit)
	my_strcat(buffer, "nourriture");
      ret += 10;
      found = 1;
    }
  return (ret + get_cell_rocks(cell, buffer, found, doit));
}
