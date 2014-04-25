/*
** welcome.c for welcome in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Wed Apr  7 13:26:57 2010 mathieu1 lornac
** Last update Sat Apr 24 14:01:20 2010 damien1 coppel
*/

#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "ip_protocol.h"
#include "server.h"
#include "position.h"
#include "process_clients.h"
#include "str_utils.h"
#include "map.h"
#include "request.h"
#include "client_management.h"
#include "team_management.h"
#include "time_management.h"
#include "life_management.h"
#include "action.h"
#include "action_gr.h"
#include "egg_management.h"

/*
** Removes the client from the client list
** Registers it as a graphic client
*/
int		first_graphic_talk(t_list **list_clients, t_client *cl)
{
  if (vars->graphic_client)
    {
      my_printf("Graphic client already connected\n");
      remove_client(list_clients, cl, 1);
      return (2);
    }
  my_printf("Graphic client connected\n");
  remove_client(list_clients, cl, 0);
  vars->graphic_client = cl;
  cl->to_send = NULL;
  cl->to_send = map_size_gr();
  cl->to_send = dupcat(cl->to_send, time_ask_unit_gr());
  cl->to_send = dupcat(cl->to_send, map_all_case_content_gr());
  cl->to_send = dupcat(cl->to_send, team_name_gr());
  cl->to_send = dupcat(cl->to_send, player_all_connect_gr());
  cl->to_send = dupcat(cl->to_send, egg_all_on_map_gr());
  cl->to_send_len = my_strlen(cl->to_send);
  return (2);
}

void		send_first_info(t_client *cl, int can_join)
{
  char	*sx;
  char	*sy;
  char	*ch_map;

  cl->to_send = add_bn(my_sprintf(can_join));
  sx = my_sprintf(map_size.x);
  sy = my_sprintf(map_size.y);
  ch_map = xmalloc(sizeof(*ch_map) * (my_strlen(sx) + my_strlen(sy) + 3));
  my_strcpy(ch_map, sx);
  my_strcat(ch_map, " ");
  my_strcat(ch_map, sy);
  my_strcat(ch_map, "\n");
  cl->to_send = dupcat(cl->to_send, ch_map);
  free(sx);
  free(sy);
  cl->to_send_len = my_strlen(cl->to_send);
  send_to_graph(player_connect_gr(cl));
}

/*
** Inits the client in the client list
*/
int		first_client_talk(t_list **list_clients, t_client *cl)
{
  int		can_join;
  int		max_player_team;
  t_pos		*pos;

  if ((!is_a_registered_team(cl->team_name)) ||
      (get_nb_players_on_team(cl->team_name) >
       (max_player_team = get_nb_players_max_on_team(cl->team_name))))
    {
      my_printf("Team incorrect or too many players: %s\n", cl->team_name);
      remove_client(list_clients, cl, 1);
      return (2);
    }
  pos = connect_player_on_egg(cl->team_name);
  if (pos)
    {
      set_pos(&cl->pos, pos);
      free(pos);
    }
  else
    position_player_on_map(&(cl->pos));
  my_printf("Client on socket %d joined: %s\n", cl->socket, cl->team_name);
  can_join = max_player_team - get_nb_players_on_team(cl->team_name);
  send_first_info(cl, can_join);
  return (1);
}

/*
** On the first talk it initializes the client and returns 1
** Returns 0 if the client is uninitialized
** Returns 2 if too many clients in the team
*/
int		first_talk(t_list **list_clients, t_client *cl, char *request)
{
  if (cl->team_name)
    return (0);
  cl->team_name = del_bn(my_strdup(request));
  if (!my_strcmp("GRAPHIC", cl->team_name))
    return (first_graphic_talk(list_clients, cl));
  else
    return (first_client_talk(list_clients, cl));
}
