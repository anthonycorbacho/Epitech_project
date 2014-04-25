/*
** map.h for map in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 17:18:06 2010 mathieu1 lornac
** Last update Thu Apr 22 13:57:12 2010 mathieu1 lornac
*/

#ifndef __MAP_H__
#define __MAP_H__

/*
** Food and rock densities [0..100]
*/
#define	MAP_FOOD 60
#define MAP_ROCK 30

typedef unsigned char uchar;

/*
** Map element
*/
typedef	struct	s_map_elt
{
  uchar		food;			/*food quantity on the map elt*/
  uchar		rocks[NB_ROCKS];	/*Quantity by rock*/
}		t_map_elt;

/*
** Map type
*/
typedef t_map_elt* t_map;

/*
** Map global variable
*/
extern t_map *map;
extern t_pos map_size;

/*
** Positions the player on the map
*/
void			position_player_on_map(t_pos *pos);

/*
** Returns a poiter on the corresponding cell
*/
void			set_initialize_map(int y, int x);

/*
** Add to the map a ramdon food & rocks
*/
void			rand_initialize_map(int y, int x);

/*
** Returns a pointer on the corresponding cell
*/
t_map_elt		*get_cell(int x, int y);

/*
** Translates the coordinates of pos into coordinates directly accessible
** Ex with map_size == 50, 50: (-1, 48) => (49, 48)
*/
void			tranlate_coords(t_pos *pos, t_pos *out);

/*
** Mallocs and resets the map to the specified size
*/
void			initialize_map(int x, int y);

/*
** Liberates the map
*/
void			free_map();

#endif /*__MAP_H__*/
