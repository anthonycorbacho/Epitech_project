/*
** initialize_connexion.c for init network\ in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb 23 18:01:17 2010 anthony1 corbacho
** Last update Sat Mar 13 19:31:50 2010 anthony1 corbacho
*/

#include		<unistd.h>
#include		<signal.h>
#include		"header_client.h"

s_client       		initialize_connexion(char **arg, s_client cl)
{

  cl.server_socket = socket(PF_INET, SOCK_STREAM, 0);
  if (cl.server_socket < 0)
    my_erno(3, "Socket Failled\n");
  cl.port = my_getnbr(arg[2]);
  cl.sin.sin_family = AF_INET;
  cl.sin.sin_port = htons(cl.port);
  if (my_strcmp(arg[1], "localhost") == 0)
    cl.sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  else
    cl.sin.sin_addr.s_addr = inet_addr(arg[1]);
    welcome_client();
    cl.read = 0;
  return (cl);
}

void			lunch_client(char **arg)
{
  s_client		client;

  client = initialize_connexion(arg, client);
  if (connect(client.server_socket, (struct sockaddr *)&(client.sin),
	      sizeof (struct sockaddr_in)) == -1)
    {
      close(client.server_socket);
      my_erno(3, "Error: Host not found\n");
    }
  while (my_strcmp(client.cmd, "quit") != 0)
    {
      my_memset(client.cmd, 0, BUFF_MIN);
      xwrite(1, "ftp > ", my_strlen("ftp > "));
      client.read = read(0, client.cmd, BUFF_MIN);
      client.cmd[client.read - 1] = '\0';
      if (my_strcmp(client.cmd, "quit") != 0 &&
	  my_strcmp(client.cmd, "") != 0)
	exec_cmd(client);
    }
  good_bye_client();
  shutdown(client.server_socket, 2);
  close(client.server_socket);
}
