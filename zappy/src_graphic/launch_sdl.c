/*
** launch_sdl.c for in /home/anthony/Zappy/src_graphic
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Apr  7 13:16:12 2010 anthony1 corbacho
** Last update Tue Apr 20 20:04:23 2010 anthony1 corbacho
*/

#include "sdl_function.h"
#include "sdl_print_items.h"
#include "sdl_function_next.h"
#include "sdl_init_map.h"
#include "sdl_user.h"
#include "sdl_movement_radar.h"
#include "sdl_event_management.h"
#include "xsdl.h"

#include "put_menu_monster.h"
#include "put_menu_minimap.h"

#include "put_menu.h"
#include "user.h"
#include "map.h"
#include "definitions.h"
#include "map_initialize.h"

#include "lmy_printf.h"
#include "lxsys.h"

/*
** Thread who manage the SDL event [update map]
*/
int		movement_map(void *param)
{
  t_sdl		*sdl;

  sdl = (t_sdl *)param;
  while (42)
    {
      print_init_map(sdl);
      put_items_map(sdl);
      put_users(sdl);
      put_menu_minimap_sdl(sdl);
      SDL_UpdateRects(sdl->screen, 1, &sdl->game.pos_player);
      SDL_UpdateRects(sdl->screen, 1, &sdl->game.pos_item);
      event_radar(sdl);
      SDL_UpdateRect(sdl->screen, 0, 0, 0, 0);
      SDL_Delay(15);
    }
  return (0);
}

/*
**
*/
void		waiting_server()
{
  int		i;

 i = 1;
 while (!map_size.x && !map_size.y)
   {
     if (i == 1)
       {
	 my_printf("Waiting server informations\n");
	 i = 0;
       }
     my_printf("", map_size.x, map_size.y);
   }
}

void		launch_sdl(t_elem *elem)
{
  t_sdl		*main_sdl;
  SDL_Thread	*th_sdl;

  waiting_server();
  main_sdl = xmalloc(sizeof(t_sdl));
  initialise_sdl_window(main_sdl);
  xSDL_EnableKeyRepeat(70, 70);
  main_sdl->elem = elem;
  if ((th_sdl = SDL_CreateThread(movement_map, (void *)main_sdl)) == NULL)
    {
      my_printf("Error\n");
      return ;
    }
  event_management(main_sdl);
  SDL_KillThread(th_sdl);
  free_struct_sdl(main_sdl);
  free(main_sdl);
  free(elem->user);
}
