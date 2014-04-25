/*
** get_file.c for get the file in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/src_server
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Mar  8 17:57:49 2010 anthony1 corbacho
** Last update Sat Mar 13 19:03:45 2010 anthony1 corbacho
*/

#include		<sys/stat.h>
#include		<sys/types.h>
#include		<fcntl.h>
#include		<sys/stat.h>
#include		"header_server.h"

int			verif_arg(char *cmd)
{
  char			*file;
  struct stat		st;

  if (cmd[3] == '\0')
    return (-1);
  file = extrat_path(cmd);
  if (access(file, F_OK | R_OK) == -1)
    {
      xfree(file);
      return (-1);
    }
  if (stat(file, &st) == -1)
    return (-1);
  if (S_ISDIR(st.st_mode))
    return (-1);
  xfree(file);
  return (1);
}

int			init_transfert(s_server srv)
{
  struct stat		st;
  char			*file;

  file = extrat_path(srv.cmd);
  if (file == NULL)
    return (0);
  if (lstat(file, &st) == -1)
    {
      my_putstr("Error on the file\n");
      xfree(file);
      return (0);
    }
  xfree(file);
  return (1);
}

int			 send_struct_to_client(char *file, s_server srv)
{
  struct stat		st;
  int			fd_stat;

  fd_stat = 0;
  fd_stat = stat(file, &st);
  my_send(srv.socket_client, &st, sizeof(st), (int)NULL);
  return (1);
}

int			get_the_file(s_server srv)
{
  int			nb_octel_read;
  int			open_file;
  char			*file;
  char			buffer[BUFF_MAX];

  nb_octel_read = 0;
  open_file = 0;
  file = extrat_path(srv.cmd);
  if ((open_file = open(file, O_RDWR)) == -1)
    {
      my_send(srv.socket_client, "400", 3, (int)NULL);
      xfree(file);
      return (0);
    }
  send_struct_to_client(file, srv);
  while ((nb_octel_read = read(open_file, buffer, BUFF_MAX)) > 0)
    my_send(srv.socket_client, buffer, nb_octel_read, (int)NULL);
  if (nb_octel_read == -1)
    my_send(srv.socket_client, "400", 3, (int)NULL);
  else
    my_send(srv.socket_client, "200", 3, (int)NULL);
  close(open_file);
  return (1);
}

void			get_file(s_server srv)
{

  my_putstr("Trying to open ");
  my_putstr(srv.cmd);
  my_putchar('\n');
  if (verif_arg(srv.cmd) == -1)
    my_send(srv.socket_client, "400", 3, (int)NULL);
  else
    {
      my_send(srv.socket_client, srv.cmd, my_strlen(srv.cmd),
	      (int)NULL);
      init_transfert(srv);
      get_the_file(srv);
    }
}
