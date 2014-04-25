/*
** exec_cmd.c for execute cmd in /home/anthony/Projet/my_ftp/src_server
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Feb 25 13:36:09 2010 anthony1 corbacho
** Last update Fri Mar 12 12:23:16 2010 anthony1 corbacho
*/

#include			<string.h>
#include			<sys/types.h>
#include			<dirent.h>
#include			<sys/wait.h>
#include			<unistd.h>
#include			"header_server.h"

void				send_pwd(s_server srv)
{
  char				pwd[BUFF_MIN];
  pid_t				pid;

  pid = xfork();
  if (pid == 0)
    {
      memset(pwd, '\0', BUFF_MIN);
      my_putchar('~');
      my_putstr(" pwd\n");
      if (getwd(pwd) != NULL)
	{
	  my_send(srv.socket_client, pwd, my_strlen(pwd), (int)NULL);
	  my_send(srv.socket_client, "220", 7, (int)NULL);
	  my_putstr("Code 200: Transfert sucessfull\n");
	}
      else
	{
	  my_send(srv.socket_client, "pwd Failled\n", 12, (int)NULL);
	  my_send(srv.socket_client, "420", 7, (int)NULL);
	  my_putstr("Error 400: Transfert Failled\n");
	}
    }
  else
    xwait(NULL);
}

void				put_cat(char **total, char *name)
{
  my_strcat_(*total, name);
  my_strcat_(*total, "\n");
}

int				show_ls(s_server srv)
{
  struct dirent			*d;
  DIR				*dir;
  char				*total;
  int				total_len;

  total_len = 0;
  if ((dir = opendir(".")) != 0)
    {
      while ((d = readdir(dir)))
	total_len += 1 + total_len + my_strlen(d->d_name);
      total= xmalloc((total_len) * sizeof(*total));
      closedir(dir);
      dir = opendir(".");
      total[0] = '\0';
      while ((d = readdir(dir)))
	put_cat(&total, d->d_name);
      closedir(dir);
      my_send(srv.socket_client, total, my_strlen(total), (int)NULL);
      free(total);
    }
  else
    return (0);
  return (1);
}

void				send_ls(s_server srv)
{
  pid_t				pid;

  pid = xfork();
  if (pid == 0)
    {
      my_putchar('~');
      my_putstr(" ls\n");
      if (show_ls(srv) == 1)
	{
	  my_send(srv.socket_client, "220", 7, (int)NULL);
	  my_putstr("Code 200: Transfert sucessfull\n");
	}
      else
	{
	  my_send(srv.socket_client, "451", 6, (int)NULL);
	  my_putstr("Error 400: Transfert failled!\n");
	}
    }
  else
    xwait(NULL);
}

void				exec_cmd_client(s_server srv)
{
  if (my_strcmp(srv.cmd, "pwd") == 0)
    send_pwd(srv);
  if (my_strcmp(srv.cmd, "ls") == 0)
    send_ls(srv);
  if (my_strncmp_(srv.cmd, "cd", 2) == 0)
    send_cd(srv);
  if (my_strncmp_(srv.cmd, "put", 3) == 0)
    put_file(srv);
  if (my_strncmp_(srv.cmd, "get", 3) == 0)
    get_file(srv);
}
