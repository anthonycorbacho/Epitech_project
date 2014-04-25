/*
** player3_gr.c for zappy in /home/damien/work_local/za
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 16:05:49 2010 damien1 coppel
** Last update Sun Apr 25 19:06:24 2010 damien1 coppel
*/

#include "server.h"
#include "position.h"
#include "str_utils.h"
#include "lstr.h"
#include "lxsys.h"
#include "server.h"
#include "action_gr.h"

/*
** Returns a string containing all the player numbers on a specified cell
** the player wich has the number creator is not listed
** list as follows: #n #n #n...
*/
char		*list_clients_on_cell(t_list *cls, t_client *client)
{
  t_client	*cl;
  char		*to_send;
  char		*tmp;

  to_send = NULL;
  while (cls)
    {
      cl = cls->data;
      if (cl->id != client->id &&
	  cl->pos.x == client->pos.x && cl->pos.y == client->pos.y)
	{
	  to_send = dupcat(to_send, my_strdup(" #"));
	  tmp = my_sprintf(cl->id);
	  to_send = dupcat(to_send, tmp);
	}
      cls = cls->next;
    }
  return (to_send);
}

/*
** Player starts an incantation for everyone on a map cell
** pic X Y L #n #n ...\n
*/
char		*player_incantation_start_gr(t_client *client)
{
  char		*to_send;
  char		*coordinate;
  char		*ic_lvl;
  char		*p_id;
  int		len;

  coordinate = del_bn(extract_coordinates_from_pos(&(client->pos)));
  ic_lvl = my_sprintf(client->level);
  p_id = my_sprintf(client->id);
  len = 9 + my_strlen(coordinate) + my_strlen(ic_lvl) + my_strlen(p_id);
  to_send = xmalloc(len);
  my_strcpy(to_send, "pic ");
  my_strcat(to_send, coordinate);
  my_strcat(to_send, " ");
  my_strcat(to_send, ic_lvl);
  my_strcat(to_send, " #");
  my_strcat(to_send, p_id);
  to_send = dupcat(to_send, list_clients_on_cell(vars->list_clients,
						 client));
  my_strcat(to_send, "\n");
  xfree_n(coordinate, ic_lvl, p_id, (void *)-1);
  return (to_send);
}

/*
** End incantation
** pie X Y R\n
*/
char		*player_incantation_end_gr(t_client *client, int result)
{
  char		*to_send;
  char		*coordinate;
  char		*inc_num;
  int		len;

  coordinate = del_bn(extract_coordinates_from_pos(&(client->pos)));
  inc_num = my_sprintf(result);
  len = 7 + my_strlen(coordinate) + my_strlen(inc_num);
  to_send = xmalloc(len);
  my_strcpy(to_send, "pie ");
  my_strcat(to_send, coordinate);
  my_strcat(to_send, " ");
  my_strcat(to_send, inc_num);
  my_strcat(to_send, "\n");
  xfree_n(coordinate, inc_num, (void *)-1);
  return (to_send);
}

/*
** The player drops a resource
** pdr #n i\n
*/
char		*player_drop_ressource_gr(t_client *client, int ressource_id)
{
  char		*to_send;
  char		*player_num;
  char		*res_num;
  int		len;

  player_num = my_sprintf(client->id);
  res_num = my_sprintf(ressource_id);
  len = 8 + my_strlen(player_num) + my_strlen(res_num);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "pdr #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, " ");
  my_strcat(to_send, res_num);
  my_strcat(to_send, "\n");
  xfree_n(player_num, res_num, (void *)-1);
  return (to_send);
}

/*
** The player gets a resource
** pgt #n i\n
*/
char		*player_get_ressource_gr(t_client *client, int ressource_id)
{
  char		*to_send;
  char		*player_num;
  char		*res_num;
  int		len;

  player_num = my_sprintf(client->id);
  res_num = my_sprintf(ressource_id);
  len = 8 + my_strlen(player_num) + my_strlen(res_num);
  to_send = xmalloc(len * sizeof(*to_send));
  my_strcpy(to_send, "pgt #");
  my_strcat(to_send, player_num);
  my_strcat(to_send, " ");
  my_strcat(to_send, res_num);
  my_strcat(to_send, "\n");
  xfree_n(player_num, res_num, (void *)-1);
  return (to_send);
}
