/*
** server.h for server def in /home/matt/work/my_irc/my_irc/src_server/inc
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Thu Mar  4 17:21:41 2010 mathieu1 lornac
** Last update Fri Apr 16 16:08:44 2010 damien1 coppel
*/

#ifndef __SERVER_H__
#define __SERVER_H__

#include <pthread.h>
#include <sys/time.h>
#include "definitions.h"
#include "llist.h"
#include "commands_srv.h"

/*
** Request structure
*/
typedef struct		s_request
{
  struct timeval	end_time;		/*End of instruction*/
  char			*request;		/*Request string*/
  char			*out;			/*Out buffer*/
  t_command		*cmd;
}			t_request;

/*
** Arguments reception
*/
typedef struct		s_zappy_args
{
  int			port;
  int			nb_teams;
  char			**team_names;
  int			team_max_size;
  int			time;
}			t_zappy_args;

/*
** Team structure
*/
typedef struct		s_team
{
  char			*team_name;
  int			max_team_size;
}			t_team;

/*
** time use for the egg
*/
#define EGG_TIME_ECLO 600
#define EGG_TIME_DIE 600

/*
** Client buffer request reading size
*/
#define BUFFER_SIZE 32

/*
** Client definition
** Client representation on server side
*/
typedef struct s_client
{
  int		id;			/*Identification number*/
  int		socket;			/*File descriptor to the client*/
  char		*team_name;		/*Team name*/
  t_pos		pos;			/*Current position on the map*/
  int		orientation;		/*Looking direction (0 left, 1 up...)*/
  int		level;			/*Current level of the player*/
  int		life;			/*PLayer's life*/
  int		rocks[NB_ROCKS];	/*Rock possesed by the player*/
  struct timeval next_meal;		/*Will eat at this time*/
  char		request[BUFFER_SIZE];	/*Request string*/
  char		*in;			/*In pointer on request buffer*/
  char		*out;			/*Out pointer on request buffer*/
  t_list	*requests;		/*Commands received not treated_yet*/
  char		*to_send;		/*Data waiting to be sent to the client*/
  int		already_sent;		/*Data already sent*/
  int		to_send_len;		/*Data length that has to be sent*/
}		t_client;

/*
** Main variables structure
*/
typedef struct	s_var
{
  t_list	*list_clients;		/*Graphic client*/
  t_client	*graphic_client;	/*Team list*/
  t_team	**team_list;		/*List of authorised teams on server*/
  t_list	*egg_list;		/*List of the eggs on the server*/
  int		latence;
}		t_var;

/*
** Pointer on the program main variables
*/
extern t_var *vars;

/*
** Maximum nb of requests untreated by client
*/
#define MAX_REQUESTS_CLIENT 10

/*
** Read and send sizes
*/
#define CLIENT_READ_SIZE 8
#define CLIENT_SEND_SIZE 1024

/*
** Default values for options
*/
#define DEFAULT_X_MAP 50
#define DEFAULT_Y_MAP 50
#define DEFAULT_TEAM_SIZE 8

int		sog_server_port(int);

/*
** Close the server port
** Liberates the var structure
*/
void		term_server();

/*
** NB of players of max level to win the game
*/
#define NB_PLAYERS_TO_WIN 6

#define FD_CLOSING_ERROR "Close fd error\n"

#endif /*__SERVER_H__*/
