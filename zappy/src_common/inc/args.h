/*
** args.h for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a/src_server
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Mar 24 10:20:44 2010 matias1 hastaran
** Last update Fri Apr 16 15:03:51 2010 thomas1 salomon
*/

#ifndef __MY_ZAPPY_ARGS_H__
#define __MY_ZAPPY_ARGS_H__

#include "server.h"

void		print_usage();
int		verif_args_validity(char *, char);
int		checks_args(int, char **, char *);
int		find_opt_values(int, char **, t_zappy_args *);
int		find_port(int, char **);
int		find_pos(int, char **, char *);
int		find_map_x(int, char **);
int		find_map_y(int, char **);
int		find_guest(int, char **);
int		find_time(int, char **);
int		find_team_name(int, char **, t_zappy_args *);
int		copy_name(int, char **, t_zappy_args *, int);
void		default_name(t_zappy_args *);
#endif	/*__MY_ZAPPY_ARGS_H__*/
