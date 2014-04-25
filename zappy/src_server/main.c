/*
** main.c for main file in /home/matt/work/my_irc/my_irc
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Thu Mar  4 13:41:08 2010 mathieu1 lornac
** Last update Sat Apr 24 17:37:55 2010 mathieu1 lornac
*/

#include <signal.h>
#include <stdlib.h>

#include "llist.h"
#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "args.h"
#include "definitions.h"
#include "ip_connection.h"
#include "server.h"
#include "process_clients.h"
#include "client_management.h"
#include "map.h"
#include "team_management.h"

/*
** Global variable
*/
t_var *vars;

void		malloc_vars()
{
  vars = xmalloc(sizeof(*vars));
  vars->list_clients = NULL;
  vars->graphic_client = NULL;
  vars->team_list = NULL;
  vars->egg_list = NULL;
}

/*
** Close the server port
** Liberates the var structure
*/
void		term_server()
{
  my_printf("\b\bServer is going down...\n");
  while (vars->list_clients)
    remove_client(&vars->list_clients, vars->list_clients->data, 1);
  my_free_all_list_struct(vars->list_clients);
  close_connection_ipc(sog_server_port(-1));
  my_printf("Zappy server down... bye bye\n");
  free_teams(vars->team_list);
  free(vars);
  free_map();
  exit(0);
}

void		do_nothing()
{
}

int		ret_and_free()
{
  free(vars);
  return (0);
}

int		main(int ac, char **av)
{
  int		server_fd;
  t_zappy_args	opt;

  signal(SIGPIPE, do_nothing);
  malloc_vars();
  if (ac >= 3)
    {
      if (!checks_args(ac, av, "pxynct") || !find_opt_values(ac, av, &opt))
	print_usage();
      else
	{
	  vars->latence = opt.time;
	  signal(SIGINT, term_server);
	  server_fd = connect_server_ipc(sog_server_port(-1), 10);
	  my_printf("server connected to port: %d\n", sog_server_port(-1));
	  initialize_map(map_size.x, map_size.y);
	  rand_initialize_map(map_size.x, map_size.y);
	  vars->team_list = init_teams(opt.team_names, opt.nb_teams,
				       opt.team_max_size);
	  process_clients(server_fd);
	}
    }
  else
    print_usage();
  return (ret_and_free());
}
