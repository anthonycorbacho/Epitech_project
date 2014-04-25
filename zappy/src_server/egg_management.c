/*
** egg_management.c for egg_management in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sat Apr 10 14:35:43 2010 mathieu1 lornac
** Last update Sun Apr 25 19:30:30 2010 mathieu1 lornac
*/

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "server.h"
#include "time_management.h"
#include "egg_management.h"
#include "team_management.h"
#include "action.h"
#include "action_gr.h"
#include "position.h"

/*
** Compares the id of 2 eggs
*/
int		egg_cmp(t_egg *e1, t_egg *e2)
{
  return (e1->id - e2->id);
}

/*
** Compares team names
*/
int		egg_team_name_cmp(t_egg *e1, t_egg *e2)
{
  return (my_strcmp(e1->team_name, e2->team_name));
}

/*
** Creates a new egg associated whith the team name and player
*/
int		new_egg(t_client *cl)
{
  t_egg		*egg;
  static int	egg_id = 0;
  t_team	*team;

  egg = xmalloc(sizeof(*egg));
  egg->id = egg_id++;
  egg->client = cl;
  egg->team_name = my_strdup(cl->team_name);
  egg->status = 0;
  set_pos(&egg->pos, &cl->pos);
  xgettimeofday(&(egg->expiration_date), 0);
  add_time(&(egg->expiration_date), 1000000 * EGG_TIME_ECLO);
  my_printf("Egg with id: %d has been created\n", egg->id);
  team = get_team_by_name(cl->team_name);
  team->max_team_size++;
  my_put_elem_in_list(&vars->egg_list, egg);
  return (egg->id);
}

/*
** Remove an egg from the egg list
** If connected == 0 decrements the team size (Egg dead)
*/
void		remove_egg(int id_egg, int connected)
{
  t_egg		ref;
  t_egg		*c;
  t_team	*team;

  ref.id = id_egg;
  my_printf("Egg with id: %d has been removed\n", id_egg);
  c = my_find_elm_eq_in_list(vars->egg_list, &ref, egg_cmp);
  my_rm_all_eq_from_list(&vars->egg_list, &ref, egg_cmp);
  if (!connected)
    {
      team = get_team_by_name(c->team_name);
      team->max_team_size--;
    }
  free(c->team_name);
  free(c);
}

/*
** Checks if the egg status has expired
** Change it's status if necessary
** Removes it from the list if needed
*/
void		check_on_eggs()
{
  t_list	*cur;
  t_egg		*egg;

  cur = vars->egg_list;
  while (cur)
    {
      egg = ((t_egg*)(cur->data));
      if (time_is_reach(&(egg->expiration_date)))
	{
	  ++(egg->status);
	  if (egg->status > 1)
	    {
	      send_to_graph(egg_born_die_hungry_gr(egg));
	      remove_egg(egg->id, 0);
	      break;
	    }
	  else
	    {
	      xgettimeofday(&(egg->expiration_date), 0);
	      add_time(&(egg->expiration_date), 1000000 * EGG_TIME_DIE);
	      my_printf("Egg with id: %d has hatched\n", egg->id);
	      send_to_graph(egg_born_gr(egg));
	    }
	}
      cur = cur->next;
    }
}
