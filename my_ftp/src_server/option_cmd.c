/*
** option_cmd.c for cmd in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri Mar  5 13:21:59 2010 anthony1 corbacho
** Last update Fri Mar 12 11:50:34 2010 anthony1 corbacho
*/

#include		"header_server.h"

char			pwd[BUFF_MIN];

int			count_slash(char *str)
{
  int			i;
  int			nb_slash;

  i = 0;
  nb_slash = 0;
  while (str[i])
    {
      if (str[i] == '/')
	nb_slash++;
      i++;
    }
  return (nb_slash);
}

char			*extract_cmd_server(char *cmd)
{
  int			cpt;
  int			i;
  char			*path;
  int			i2;

  cpt = 2;
  i = 3;
  i2 = 0;
  while (cmd[cpt])
    cpt++;
  path = xmalloc((cpt - 2) * sizeof(path));
  while (i < cpt)
    {
      path[i2] = cmd[i];
      i++;
      i2++;
    }
  path[i2] = '\0';
  return (path);
}

int			test_racine(char *path, char *to_test, s_server srv)
{
  int			nb_slash_path;
  int			nb_slash_to_test;

  nb_slash_to_test = 0;
  nb_slash_path = 0;
  nb_slash_path = count_slash(path);
  nb_slash_to_test = count_slash(to_test);
  if ((nb_slash_to_test < nb_slash_path) || my_strncmp_(path, to_test,
							my_strlen(path) == 0))
    {
      if (chdir(path) == -1)
	my_putstr("Serv: error on change dir\n");
      my_send(srv.socket_client, "No such directory\n", 18, (int)NULL);
      my_send(srv.socket_client, "400", 3, (int)NULL);
    }
  else
    {
      my_send(srv.socket_client, "Changer dir done\n", 18, (int)NULL);
      my_send(srv.socket_client, "200", 3, (int)NULL);
    }
  return (1);
}

void			send_cd(s_server srv)
{
  char			*path_cd;
  char			pwd_cur[BUFF_MIN];

  my_putchar('~');
  my_putstr(" cd\n");
  if (my_strlen(srv.cmd) == my_strlen("cd"))
    my_putstr("cd need directory\n");
  else
    {
      path_cd = extract_cmd_server(srv.cmd);
      if (chdir(path_cd) == -1)
	{
	  my_send(srv.socket_client, "No such directory\n", 18, (int)NULL);
	  my_send(srv.socket_client, "400", 3, (int)NULL);
	}
      else
	{
	  getwd(pwd_cur);
	  test_racine(pwd, pwd_cur, srv);
	}
      xfree(path_cd);
    }
}
