/*
** put_function.c for function put in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb 23 23:41:52 2010 anthony1 corbacho
** Last update Fri Mar 12 11:39:49 2010 anthony1 corbacho
*/

#include			<string.h>
#include			<unistd.h>
#include			"header_client.h"

void				view_query(char *str, s_client cl)
{
  int				size_recv;
  int				len_tot;
  char				*querry;

  my_memset(str, 0, BUFF_MAX);
  querry = str;
  len_tot = 0;
  size_recv = my_recv(cl.server_socket, str, BUFF_MAX, (int)NULL);
  while (querry[size_recv] != '\0' && (len_tot < BUFF_MAX))
    {
      querry = &(querry[size_recv]);
      my_putstr(querry);
      size_recv = my_recv(cl.server_socket, querry, BUFF_MAX, (int)NULL);
      len_tot = len_tot + size_recv;
    }
  my_putstr(str);
  my_recv(cl.server_socket, querry, BUFF_MAX, (int)NULL);
  querry[3] = '\0';
  if (querry[0] == '2')
    my_putstr("\nSucess\n");
  else
    my_putstr("\nError\n");
}

void				put_pwd(s_client cl)
{
  char				server_querry[BUFF_MAX];

  my_send(cl.server_socket, "pwd", my_strlen("pwd"), (int)NULL);
  view_query(server_querry, cl);
  my_putchar('\n');
}

void				put_ls(s_client cl)
{
  char				server_ls[BUFF_MAX];

  my_send(cl.server_socket, "ls", my_strlen("ls"), (int)NULL);
  view_query(server_ls, cl);
  my_memset(server_ls, 0, BUFF_MAX);
}

void				put_cd(s_client cl)
{
  char				server_cd[BUFF_MAX];

  my_send(cl.server_socket, cl.cmd, my_strlen(cl.cmd), (int)NULL);
  view_query(server_cd, cl);
}

void				put_die(s_client cl)
{
  my_send(cl.server_socket, "die", 3, (int)NULL);
}
