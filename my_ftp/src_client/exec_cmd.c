/*
** exec_cmd.c for execute cmd in /home/anthony/Projet/my_ftp/src_client
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb 23 23:29:11 2010 anthony1 corbacho
** Last update Tue Mar  9 13:55:45 2010 anthony1 corbacho
*/

#include		"header_client.h"

int			valid_cmd(char *cmd)
{
  if (my_strcmp(cmd, "pwd") == 0 || my_strcmp(cmd, "ls") == 0
      || my_strncmp_(cmd, "cd", 2) == 0 || my_strcmp(cmd, "lpwd") == 0
      || my_strcmp(cmd, "lls") == 0 || my_strncmp_(cmd, "lcd", 3) == 0
      || my_strncmp_(cmd, "put", 3) == 0 || my_strcmp(cmd, "die") == 0
      || my_strncmp_(cmd, "get", 3) == 0)
    return (1);
  else
    return (0);
}


void			exec_cmd_l(s_client cl)
{
  if (my_strcmp(cl.cmd, "lpwd") == 0)
    put_lpwd();
  if (my_strcmp(cl.cmd, "lls") == 0)
    put_lls();
  if (my_strncmp_(cl.cmd, "lcd", 3) == 0)
    put_lcd(cl.cmd);
  if (valid_cmd(cl.cmd) == 0)
    {
      my_putstr(cl.cmd);
      my_putstr(": Invalid command\n");
    }
}

void			exec_cmd(s_client cl)
{
  my_putstr(cl.cmd);
  my_putstr(" was sended.\n");
  if (my_strcmp(cl.cmd, "pwd") == 0)
    put_pwd(cl);
  if (my_strcmp(cl.cmd, "ls") == 0)
    put_ls(cl);
  if (my_strncmp_(cl.cmd, "cd", 2) == 0)
    put_cd(cl);
  if (my_strncmp_(cl.cmd, "put ", 3) == 0)
    put_file_c(cl);
  if (my_strncmp_(cl.cmd, "get", 3) == 0)
    get_file_c(cl);
  if (my_strcmp(cl.cmd, "die") == 0)
    my_send(cl.server_socket, "die", 3, (int)NULL);
  exec_cmd_l(cl);
}
