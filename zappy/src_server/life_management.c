/*
** life_management.c for zappy in /home/damien/work_local/zappy/src_server
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Mar 24 10:29:25 2010 damien1 coppel
** Last update Sun Apr 25 18:19:55 2010 mathieu1 lornac
*/

#include <stdlib.h>
#include <unistd.h>

#include "llist.h"
#include "lmy_printf.h"
#include "lxsys.h"

#include "action_gr.h"
#include "action.h"
#include "life_management.h"
#include "time_management.h"
#include "server.h"
#include "process_clients.h"
#include "client_management.h"
#include "ip_protocol.h"
#include "map.h"

void		set_next_meal(struct timeval *next_meal)
{
  add_time(next_meal, 1000000 * FOOD_SPAN);
}

void		add_food_on_map()
{
  t_map_elt	*cell;

  cell = get_cell(rand() % map_size.x, rand() % map_size.y);
  cell->food++;
}

/*
** For all players :
** Decrease a life unit all the 126/TIME_UNIT
** if the life reach 0, the client die
*/
void		check_life()
{
  t_list		*cur;
  t_client		*client;

  cur = vars->list_clients;
  while (cur)
    {
      client = ((t_client*)(cur->data));
      if (client->team_name && time_is_reach(&(client->next_meal)))
	{
	  add_food_on_map();
	  --(client->life);
	  my_printf("client %d is eating, remains %d food\n", client->id, client->life);
	  set_next_meal(&(client->next_meal));
	  if (!client->life)
	    {
	      my_printf("client %d died of starvation\n", client->id);
	      xwrite(client->socket, "mort\n", 5);
	      send_to_graph(player_die_hungry_gr(client));
	      remove_client(&vars->list_clients, client, 1);
	      if (!(cur == vars->list_clients))
		break;
	    }
	}
      cur = cur->next;
    }
}
