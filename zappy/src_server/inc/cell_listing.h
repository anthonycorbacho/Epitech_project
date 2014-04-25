/*
** cell_listing.h for cell_listing in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Thu Mar 25 13:57:55 2010 mathieu1 lornac
** Last update Tue Apr  6 17:42:30 2010 mathieu1 lornac
*/

#ifndef __CELL_LISTING_H__
#define __CELL_LISTING_H__

/*
** Concatenates the players to the buffer
*/
void		get_players_on_cell(t_pos *cell, char *buffer, int doit);

/*
** List the rocks contained in the cell
*/
int		get_cell_rocks(t_map_elt *cell, char *buffer, int found, int doit);

/*
** Returns a string describing the cell content
** String format: nourriture nourriture linemate
*/
int		get_cell_content(t_pos *pos, char *buffer, int p_id, int doit);

#endif /*__CELL_LISTING_H__*/
