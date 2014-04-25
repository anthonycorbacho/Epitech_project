/*
** pthread_listen.c for zappy in /home/matias/Dropbox/Zappy/src_graphic
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Apr  7 10:43:35 2010 matias1 hastaran
** Last update Fri Apr 23 14:28:07 2010 anthony1 corbacho
*/

#include "SDL.h"
#include "SDL_thread.h"
#include "ip_protocol.h"
#include "lmy.h"
#include "lstr.h"
#include "lmy_printf.h"
#include "str_utils.h"
#include "lxsys.h"

#include "pin.h"
#include "definitions.h"
#include "map.h"
#include "define_graphic.h"
#include "gnl_socket.h"
#include "user.h"
#include "structure_server.h"
#include "thread_listen.h"

t_func		func[17] = {
  {"msz", msz},
  {"sgt", sgt},
  {"bct", bct},
  {"tna", tna},
  {"ppo", ppo},
  {"pnw", pnw},
  {"plv", plv},
  {"pic", pic},
  {"pdi", pdi},
  {"pie", pie},
  {"pin", pin},
  {"pbc", pbc},
  {"enw", enw},
  {"eht", eht},
  {"edi", edi},
  {"ebo", edi},
  {0, 0}
};

void		fill_cell(int x, int y, char **info)
{
  t_map_elt	*map_elt;
  int		i;
  int		r;

  i = 0;
  r = 4;
  map_elt = get_cell(x, y);
  map_elt->food = my_atoi(info[3]);
  while (r < 10)
    {
      map_elt->rocks[i] = my_atoi(info[r]);
      i++;
      r++;
    }
}

void		send_pin(char *num, int socket)
{
  char		*pin;
  int		len;

  len = my_strlen(num);
  pin = xmalloc((len + 6) * sizeof(char));
  pin[0] = 0;
  my_strcat(pin, "pin #");
  my_strcat(pin, num);
  my_strcat(pin, "\n");
  my_send(socket, pin);
  free(pin);
}

void		thread_loop(t_elem *elem)
{
  int		i;
  char		*str;

  my_send(elem->socket, "sgt\n");
  while (42)
    {
      str = get_next_line_socket(elem->socket);
      i = 0;
      if (str == NULL)
	{
	  my_printf("Error Graphic \n");
	  exit(1);
	}
      while (func[i].func != 0)
	{
	  if (my_strncmp(str, func[i].func, 3) == 0)
	    func[i].ptr_func(str, elem);
	  i++;
	}
      free(str);
    }
}

int		thread_listen(void *data)
{
  t_elem	*elem;

  elem = (t_elem *) data;
  elem->user = xmalloc(sizeof(t_sdl_user));
  elem->user = NULL;
  elem->egg = xmalloc(sizeof(t_sdl_egg));
  elem->egg = NULL;
  elem->mut_egg = SDL_CreateMutex();
  elem->mut_user = SDL_CreateMutex();
  my_send(elem->socket, GRAPHIC);
  thread_loop(elem);
  return (1);
}
