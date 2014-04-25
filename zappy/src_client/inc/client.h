/*
** client.h for client in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 16:16:52 2010 mathieu1 lornac
** Last update Tue Apr 20 16:19:31 2010 matias1 hastaran
*/

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "definitions.h"
#include "map.h"

typedef struct	s_player
{
  int		server_socket;	/*Server file descriptor*/
  int		level;
  int		num_player;
  int		nbr;
  int		final;
  int		port;
  int		id;
  int		do_incant;
  int		send_flag;
  int		level_flag;
  int		food_flag;
  int		jewel_flag;
  int		move_flag;
  int		end_flag;
  int		level_ok;
  int		target_id;
  char		*jewel_name;
  char		*team_name;
  char		*host_name;
}		t_player;

#endif /*__CLIENT_H__*/
