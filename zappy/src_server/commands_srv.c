/*
** commands.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 18:13:06 2010 damien1 coppel
** Last update Tue Apr 13 15:06:26 2010 damien1 coppel
*/

#include "action.h"
#include "action_gr.h"
#include "commands_srv.h"

t_command	lst_cmd[13] = {
  {"avance", 6, 7, avance},
  {"droite", 6, 7, droite},
  {"gauche", 6, 7, gauche},
  {"voir", 4, 7, voir},
  {"inventaire", 10, 7, inventaire},
  {"prend", 5, 7, prend},
  {"pose", 4, 7, pose},
  {"expulse", 7, 7, expulse},
  {"broadcast", 9, 7, broadcast},
  {"incantation", 11, 300, incantation},
  {"fork", 4, 42, forky},
  {"connect_nbr", 11, 0, connect_nbr},
  {0, 0, 0, 0},
};

t_command	lst_cmd_gr[10] = {
  {"msz", 3, 0, map_size_gr},
  {"bct", 3, 0, cmd_gr_get_case},
  {"mct", 3, 0, map_all_case_content_gr},
  {"tna", 3, 0, team_name_gr},
  {"ppo", 3, 0, cmd_gr_player_pos},
  {"plv", 3, 0, cmd_gr_player_lvl},
  {"pin", 3, 0, cmd_gr_player_inv},
  {"sgt", 3, 0, time_ask_unit_gr},
  {"sst", 3, 0, cmd_gr_set_time},
  {0, 0, 0, 0},
};
