/*
** client.c for client in /home/matt/work/Dropbox/Epitech/Tek2/My_ftp
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Thu Feb 18 18:16:36 2010 mathieu1 lornac
** Last update Sat Apr 24 18:45:00 2010 pierre1 rolland
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"
#include "str_utils.h"

#include "definitions.h"
#include "ip_protocol.h"
#include "ip_connection.h"
#include "replicate.h"
#include "case_is_empty.h"
#include "check_case.h"
#include "client_movement.h"
#include "client.h"
#include "time.h"
#include "food.h"
#include "jewel.h"
#include "args.h"
#include "get_params.h"
#include "client_incantation.h"
#include "player_init.h"
#include "broadcast.h"
#include "broadcast_move.h"
#include "gnl_parsing.h"

#include "get_players_case.h"

void			do_nothing_client()
{
}

int			loop(t_player *p)
{
  while (p->end_flag)
    {
      check_states(p);
      if (p->food_flag == 1)
	search_food(p);
      else if (p->move_flag != -1)
	broadcast_move(p);
      else if (p->jewel_flag == 1)
	find_jewel(p, p->jewel_name);
      else if (p->do_incant == 1)
	do_incantation(p);
      else if (p->level_flag == 1)
	incantation(p);
      else
	myopic_move(p);
    }
  return (1);
}

int			check_args(t_player *p, int argc, char **argv)
{
  if (argc > 7)
    {
      my_printf("Usage Error: ./client [-h server_ip] -p port -n team_name\n");
      return (-1);
    }
  if (checks_args(argc, argv, "nph") == 0)
    {
      my_printf("Usage Error: ./client [-h server_ip] -p port -n team_name\n");
      return (-1);
    }
  if (get_params(argc, argv, p) == 0)
    {
      my_printf("Usage Error: ./client [-h server_ip] -p port -n team_name\n");
      return (-1);
    }
  return (0);
}

/*
** Main procedure
*/
int			main(int argc, char **argv)
{
  t_player		*p;

  signal(SIGPIPE, do_nothing_client);
  p = xmalloc(sizeof(*p));
  if (check_args(p, argc, argv) == -1)
    {
      free(p);
      return (-1);
    }
  srand(time(NULL));
  player_init(p);
  my_printf("client connection...\n");
  if (client_connection(p) == 1)
    loop(p);
   close_connection_ipc(p->server_socket);
  xfree_n(p->host_name, p->team_name, p, (void *)-1);
  return (0);
}
