/*
** postion.h for position in /home/matt/work/my_zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sun Mar 21 15:28:33 2010 mathieu1 lornac
** Last update Tue Apr  6 19:00:56 2010 mathieu1 lornac
*/

#ifndef __POSITION_H__
#define __POSITION_H__

/*
** Extract the coordinates of a string formated as:
** X Y\n
*/
t_pos			*extract_coordinates_from_str(char *s);

/*
** Translates the coordinates into a string formated as:
** X Y\n
*/
char			*extract_coordinates_from_pos(t_pos *p);

/*
** Sets the position of a player
** dest, source
*/
void			set_pos(t_pos *dest, t_pos *source);

/*
** Compares 2 positions
** returns 1 if pos identical, 0 otherwise
*/
int			cmp_pos(t_pos *dest, t_pos *source);

/*
** Position display (x: %d y: %d\n)
*/
void			print_pos(t_pos *p);

#endif /*__POSITION_H__*/
