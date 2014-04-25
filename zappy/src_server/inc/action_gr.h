/*
** action_gr.h for zappy in /home/damien/work_local/zappy_2012s_coppel_a/src_server/inc
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 15:15:48 2010 damien1 coppel
** Last update Thu Apr 22 15:38:01 2010 damien1 coppel
*/

#ifndef __ACTION_GR_H__
#define __ACTION_GR_H__

#include "server.h"
#include "egg_management.h"

/*
** cmd_rcv.c
*/
t_client	*get_client_by_id(int id);
int		check_for_space(char *str);

/*
** egg_gr.c
*/
char	*egg_all_on_map_gr();
char	*egg_laid_on_case_gr(t_client *client, t_egg *egg);
char	*egg_born_gr(t_egg *egg);
char	*egg_player_connected_gr(t_egg *egg);
char	*egg_born_die_hungry_gr(t_egg *egg);

/*
** map_gr.c
*/
char	*map_size_gr();
char	*map_case_content_gr(char *request);
char	*map_all_case_content_gr();

/*
** player1_gr.c, player2_gr.c, player3_gr.c
*/
char	*player_all_connect_gr();
char	*player_connect_gr(t_client *client);
char	*player_pos_gr(t_client *client);
char	*player_level_gr(t_client *client);
char	*player_inventaire_gr(t_client *client);
char	*player_expulse_gr(t_client *client);
char	*player_broadcast_gr(t_client *client, char *message);
char	*player_incantation_start_gr(t_client *client);
char	*player_incantation_end_gr(t_client *client, int result);
char	*player_lay_egg_gr(t_client *client, int egg_id);
char	*player_drop_ressource_gr(t_client *client, int ressource_id);
char	*player_get_ressource_gr(t_client *client, int ressource_id);
char	*player_die_hungry_gr(t_client *client);
char	*player_dies_gr(t_client *client);

/*
** signal_gr.c
*/
char	*signal_end_game_gr();
char	*signal_msg_serv_gr();
char	*signal_unknow_cmd_gr();
char	*signal_bad_parameter_gr();

/*
** team_gr.c
*/
char	*team_name_gr();

/*
** time_gr.c
*/
char	*time_ask_unit_gr();
char	*time_modif_unit_gr(int time_unit);

/*
** forky_gr.c
*/
char	*player_fork_gr(t_client *client);
char	*player_end_fork_gr(t_client *client, int id_egg);

/*
** Function use to answer to the graphic client
** cmd_gr.c
*/
char	*cmd_gr_get_case(char *arg);
char	*cmd_gr_player_pos(char *arg);
char	*cmd_gr_player_lvl(char *arg);
char	*cmd_gr_player_inv(char *arg);
char	*cmd_gr_set_time(char *arg);

#endif /*__ACTION_GR_H__*/
