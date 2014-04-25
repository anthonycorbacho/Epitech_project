/*
** broadcast.h for zappy client in /home/tom/zappy_2012s_coppel_a
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** 
** Started on  Tue Apr 20 18:36:14 2010 thomas1 salomon
** Last update Tue Apr 20 22:22:04 2010 matias1 hastaran
*/

#ifndef			__BROADCAST_H__
#define			__BROADCAST_H__

#include "client.h"

void			broadcast_for_level(t_player *, char *);
void			broadcast_for_move(t_player *, char *);
void			broadcast(t_player *, char *);
void			send_broadcast(t_player *);
void			check_states(t_player *);

#endif			/*__BROADCAST_H__*/
