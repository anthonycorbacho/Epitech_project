/*
** map.c for map in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 21:00:06 2010 mathieu1 lornac
** Last update Mon Apr 19 17:05:03 2010 mathieu1 lornac
*/

#include <stdlib.h>

#include "llist.h"
#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "map.h"
#include "map_initialize.h"
#include "time.h"

/*
** Map global variable
*/
t_map	*map;
t_pos	map_size;

/*
** Positions the player on the map
*/
void			position_player_on_map(t_pos *pos)
{
  pos->x = rand() % map_size.x;
  pos->y = rand() % map_size.y;
}

/*
** Set the map to default food = 0 & rocks[type_rock] = 0
*/
void			set_initialize_map(int x, int y)
{
  t_map_elt		*map_elt;
  int			cpt;
  int			cpt_2;
  int			int_rocks;

  cpt = 0;
  while (cpt < x)
    {
      cpt_2 = 0;
      while (cpt_2 < y)
	{
	  map_elt = get_cell(cpt, cpt_2);
	  map_elt->food = 0;
	  int_rocks = 0;
	  while (int_rocks < NB_ROCKS)
	    {
	      map_elt->rocks[int_rocks] = 0;
	      int_rocks++;
	    }
	  cpt_2++;
	}
      cpt++;
    }
}

/*
** Add to the map a ramdon food & rocks
*/
void			rand_initialize_map(int x, int y)
{
  t_map_elt		*map_elt;
  int			total;
  int			r;

  srand(time(NULL));
  total = MAP_FOOD * (y * x) / 100;
  while (total > 0)
    {
      map_elt = get_cell(rand() % x, rand() % y);
      map_elt->food++;
      total--;
    }
  total = (MAP_ROCK * (y * x) / 100);
  while (total > 0)
    {
      r = rand() % NB_ROCKS;
      map_elt = get_cell(rand() % x, rand() % y);
      map_elt->rocks[r]++;
      total--;
    }
  my_printf("Map init done :-)\n");
}

void			initialize_map(int x, int y)
{  
  map = xmalloc(sizeof(**map) * (x * y + 1));
  map_size.y = y;
  map_size.x = x;
  set_initialize_map(map_size.x, map_size.y);
}

/*
** Translates the coordinates of pos into coordinates directly accessible
** Ex with map_size == 50, 50: (-1, 48) => (49, 48)
*/
void		tranlate_coords(t_pos *pos, t_pos *out)
{
  if (pos->x < 0)
    out->x = map_size.x + pos->x;
  else
    out->x = pos->x % map_size.x;
  if (pos->y < 0)
    out->y = map_size.y + pos->y;
  else
    out->y = pos->y % map_size.y;
}

