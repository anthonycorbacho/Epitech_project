/*
** map_initialize.c for map_init in /home/anthony/Zappy_home/zappy_2012s_coppel_a/src_common
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Mar 24 10:47:20 2010 anthony1 corbacho
** Last update Thu Apr 22 13:56:47 2010 mathieu1 lornac
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

/*
** Function TEST: View the map
*/
void		show_map(int x, int y)
{
  int		cpt;
  int		cpt_2;
  t_map_elt	*map_elt;
  
  cpt = 0;
  while (cpt < x)
    {
      cpt_2 = 0;
      while (cpt_2 < y)
        {
	  if (cpt_2 % 10 == 0)
	    my_putchar('\n');
          map_elt = get_cell(cpt, cpt_2);
          my_printf("%d %d %d %d %d %d %d|", map_elt->food,
		    map_elt->rocks[0], map_elt->rocks[1],
		    map_elt->rocks[2], map_elt->rocks[3],
		    map_elt->rocks[4],map_elt->rocks[5]); 
          cpt_2++;
        }
      cpt++;
    }
  my_putchar('\n');
}

/*
** Return the current pointer
*/
t_map_elt		*get_cell(int x, int y)
{
  t_map_elt		*ptr;

  ptr = (t_map_elt *)(map + map_size.x * y + x);
  return (ptr);
}

void			free_map()
{
  free(map);
}
