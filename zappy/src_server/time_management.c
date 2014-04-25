/*
** time_management.c for zappy in /home/damien/work_local/my_zappy/src_server
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:13:16 2010 damien1 coppel
** Last update Sun Apr 25 19:04:27 2010 damien1 coppel
*/

#include "llist.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "server.h"
#include "process_clients.h"
#include "definitions.h"
#include "request.h"
#include "str_utils.h"
#include "time_management.h"
#include "action_gr.h"
#include "action.h"
#include "map.h"
#include "message.h"
#include "incantation.h"

/*
** Add a command to the list of command
** Return 0 on failure
*/
int			set_request_command(t_request *req)
{
  int			i;

  i = 0;
  while (lst_cmd[i].name)
    {
      if (!my_strncmp(req->request, lst_cmd[i].name, lst_cmd[i].len_name))
        {
	  req->cmd = &(lst_cmd[i]);
	  return (1);
        }
      ++i;
    }
  return (0);
}

/*
** send the info to the graph for fork and incantation action
*/
void			send_info_to_graph_if_needed(t_client *client,
						     t_request *req)
{
  if (!my_strncmp(req->request, "fork", 4))
    send_to_graph(player_fork_gr(client));
  if (!my_strncmp(req->request, "incantation", 11))
    {
      if (incantation_possible(client))
	{
	  my_printf("debut incantation player %d\n", client->id);
	  client->to_send_len += 19;
	  client->to_send = dupcat(client->to_send,
				   my_strdup("elevation en cours\n"));
	  send_to_graph(player_incantation_start_gr(client));
	}
      else
	{
	  remove_request(&(client->requests));
	  client->to_send_len += 3;
	  client->to_send = dupcat(client->to_send, my_strdup(KO));
	}
    }
}

/*
** Treat a requerst from the graphic client if there is one
*/
int			treat_request_graphic()
{
  t_list		*lst_req;
  t_request		*req;
  int			i;
  int			found;

  found = 0;
  i = -1;
  if (!vars->graphic_client)
    return (0);
  lst_req = vars->graphic_client->requests;
  if (lst_req && (req = (t_request*)(lst_req->data)))
    {
      while (lst_cmd_gr[++i].name)
	if (!my_strncmp(req->request, lst_cmd_gr[i].name,
			lst_cmd_gr[i].len_name))
	  {
	    send_to_graph(lst_cmd_gr[i].ptr_func(req->request));
	    found = 1;
	  }
      if (!found)
	send_to_graph(my_strdup("suc\n"));
      remove_request(&(vars->graphic_client->requests));
    }
  return (0);
}

/*
** Used the first time a request is read
** reject the request if it's a bad one
** else accept it and set his end time
*/
void			treat_cmd_first_time(t_request *req, t_client *client)
{
  if (!set_request_command(req))
    {
      my_printf("command refused (not found)\n");
      remove_request(&(client->requests));
      client->to_send_len += 3;
      client->to_send = dupcat(client->to_send, my_strdup(KO));
    }
  else
    {
      xgettimeofday(&(req->end_time), 0);
      add_time(&(req->end_time), 1000000 * req->cmd->time);
      send_info_to_graph_if_needed(client, req);
    }
}

/*
** check each first client request and respond if the time is up
*/
void			check_time_and_answer()
{
  t_list		*cur;
  t_request		*req;
  t_client		*client;
  char			*response;

  treat_request_graphic();
  cur = vars->list_clients;
  while (cur)
    {
      client = ((t_client*)(cur->data));
      if (client->requests && (req = (t_request*)(client->requests->data)))
	{
	  if (!(req->end_time.tv_sec))
	    treat_cmd_first_time(req, client);
	  else if (time_is_reach(&(req->end_time)))
	    {
	      response = req->cmd->ptr_func(client, req);
	      client->to_send_len += my_strlen(response);
	      client->to_send = dupcat(client->to_send, response);
	      remove_request(&(client->requests));
	    }
	}
      cur = cur->next;
    }
}
