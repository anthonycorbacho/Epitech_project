/*
** main.c for main for graphic in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr  7 10:39:52 2010 anthony1 corbacho
** Last update Tue Apr 20 16:15:54 2010 pierre1 rolland
*/

#include <stdlib.h>
#include <unistd.h>

#include "lmy_printf.h"
#include "lstr.h"
#include "lmy.h"

#include "define_graphic.h"
#include "ip_connection.h"
#include "ip_protocol.h"
#include "SDL.h"
#include "launch_sdl.h"
#include "thread_listen.h"

#include "lxsys.h"
#include "definitions.h"
#include "map.h"

int		parsing_argument(char **ag, int ac)
{
  if (ac < 2 || ac > 3)
    {
      my_printf(USAGE);
      return (0);
    }
  if (ag[2] == NULL)
    {
      my_printf(USAGE);
      return (0);
    }
  if (my_str_isnum(ag[2]) < 1)
    {
      my_printf(INVALID_PORT);
      return (0);
    }
  return (1);
}

int		check_welcome_msg(int skt)
{
  char		*recv;

  recv = my_receive(skt);
  if (my_strcmp(recv, WELCOME) != 0)
    {
      my_printf(SDL_ERROR_WELCOME);
      return (0);
    }
  return (1);
}

int		main(int argc, char **argv)
{
  SDL_Thread	*thread;
  t_elem	*elem;

  elem = xmalloc(sizeof(t_elem));
  if (parsing_argument(argv, argc) != 1)
    return (0);
  elem->socket = connect_client_ipc(argv[1], my_atoi(argv[2]));
  if (check_welcome_msg(elem->socket) == 1)
    {
      if ((thread = SDL_CreateThread(thread_listen, (void *)elem)) == NULL)
	{
	  my_printf(SDL_ERROR_THREAD);
	  return (0);
	}
      sleep(2);
      launch_sdl(elem);
      SDL_KillThread(thread);
    }
  return (1);
}
