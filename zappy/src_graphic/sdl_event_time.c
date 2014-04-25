/*
** sdl_event_time.c for sdl_event_time in /home/pierre/Epitech/Projects/Zappy/
** 
** Made by pierre1 rolland
** Login   <rollan_d@epitech.net>
** 
** Started on  Sat Apr 17 22:50:50 2010 pierre1 rolland
** Last update Sun Apr 25 18:10:02 2010 pierre1 rolland
*/

#include		"structure_server.h"
#include		"sdl_structure.h"
#include		"ip_protocol.h"
#include		"lmy_printf.h"

void			event_time_up(t_sdl *sdl)
{
  char			str[9];

  if (sdl->elem->actual_time_value > 1)
    (sdl->elem->actual_time_value) /= 2;
  if ((sprintf(str, "sst %d\n", sdl->elem->actual_time_value) < 0))
    my_printf("Error sending time\n");
  my_send(sdl->elem->socket, str);
}

void			event_time_down(t_sdl *sdl)
{
  char			str[9];

  if (sdl->elem->actual_time_value < 100)
    (sdl->elem->actual_time_value) *= 2;
  if ((sprintf(str, "sst %d\n", sdl->elem->actual_time_value) < 0))
    my_printf("Error sending time\n");
  my_send(sdl->elem->socket, str);
}
