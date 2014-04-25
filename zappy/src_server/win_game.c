/*
** win_game.c for zappy in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Mon Apr 12 18:49:30 2010 mathieu1 lornac
** Last update Sun Apr 25 19:26:24 2010 mathieu1 lornac
*/

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"

#include "definitions.h"
#include "server.h"
#include "map.h"
#include "incantation.h"
#include "win_game.h"

/*
** Prints a message if a team has won the game
** Stops the game and exits
*/
void		has_won_game(t_client *client)
{
  t_client	*cl;
  t_list	*cur;
  int		occur;

  cur = vars->list_clients;
  occur = 0;
  while (cur)
    {
      cl = cur->data;
      if (cl->team_name && !my_strcmp(cl->team_name, client->team_name) &&
	  (cl->level == NB_INCANT))
	occur++;
      cur = cur->next;
    }
  if (occur >= NB_PLAYERS_TO_WIN)
    {
      my_printf("Team %s has won the game\n", client->team_name);
      term_server();
    }
}
