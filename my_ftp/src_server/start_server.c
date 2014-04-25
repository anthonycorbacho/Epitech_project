/*
** start_server.c for server in /home/anthony/Projet/my_ftp/src_server
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 24 16:10:45 2010 anthony1 corbacho
** Last update Fri Mar 12 13:29:39 2010 anthony1 corbacho
*/

#include			<unistd.h>
#include			<signal.h>
#include			"header_server.h"

extern	char			pwd[BUFF_MIN];

void				initialize_server(char **arg, s_server *srv)
{
  int				port;

  port = 0;
  srv->stop = 0;
  srv->recv = 0;
  getwd(pwd);
  srv->socket_server = socket(PF_INET, SOCK_STREAM, 0);
  if (srv->socket_server < 0)
    my_erno(3, "Socket Failled\n");
  port = my_getnbr(arg[1]);
  srv->sin.sin_family = AF_INET;
  srv->sin.sin_port = htons(port);
  srv->sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(srv->socket_server,
	   (struct sockaddr*)&(srv->sin), sizeof(srv->sin)) < 0)
    my_erno(3, "Bind failled\n");
  if (listen(srv->socket_server, 5) < 0)
    my_erno(3, "Listen Failled\n");
  srv->client_len = sizeof(srv->client_sin);
  put_server_started();
}

void				die_server_die(s_server *s)
{
  shutdown(s->socket_client, 2);
  close(s->socket_client);
  good_bye_server();
  s->stop = 1;
}

void				start_server(char **arg)
{
  s_server			srv;

  initialize_server(arg, &srv);
  while (srv.stop == 0)
    {
      srv.socket_client = accept(srv.socket_server,
				 (struct sockaddr *)&(srv.client_sin),
				 (socklen_t *)&(srv.client_len));
      if (xfork() == 0)
	{
	  close(srv.socket_server);
	  my_putstr("New client connected ... Hello... \n");
	  while (my_strcmp(srv.cmd, "die") != 0)
	    {
	      my_memset(srv.cmd, 0, BUFF_MIN);
	      srv.recv = my_recv(srv.socket_client, srv.cmd, BUFF_MIN,
				 (int)NULL);
	      srv.cmd[srv.recv] = '\0';
	      if (my_strcmp(srv.cmd, "die") != 0 ||
		  srv.cmd != NULL)
		exec_cmd_client(srv);
	    }
	  die_server_die(&srv);
	}
    }
}
