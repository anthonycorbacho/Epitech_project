/*
** put_file.c for put file in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Thu Mar  4 19:39:09 2010 anthony1 corbacho
** Last update Fri Mar 12 11:41:32 2010 anthony1 corbacho
*/

#include		<sys/stat.h>
#include		<sys/types.h>
#include		<fcntl.h>
#include		<sys/stat.h>
#include		"header_client.h"

int			verif_arguments(char *cmd)
{
  char			*file;

  if (cmd[3] == '\0')
    return (-1);
  file = extrat_path(cmd);
  if (access(file, F_OK | R_OK) == -1)
    {
      xfree(file);
      return (-1);
    }
  xfree(file);
  return (1);
}

int			prepar_transfert(s_client client)
{
  struct stat		st;
  char			*file;

  file = extrat_path(client.cmd);
  if (file == NULL)
    return (0);
  if (stat(file, &st) == -1)
    {
      my_putstr("Error on the file\n");
      xfree(file);
      return (0);
    }
  if (S_ISDIR(st.st_mode))
    {
      my_putstr("cant send a directory\n");
      return (0);
    }
  my_putstr("trying to send ");
  my_putstr(file);
  my_putchar('\n');
  xfree(file);
  return (1);
}

int			send_struct(char *file, s_client client)
{
  struct stat		st;
  int			fd_stat;

  fd_stat = 0;
  fd_stat = stat(file, &st);
  my_send(client.server_socket, &st, sizeof(st), (int)NULL);
  return (1);
}

int			send_the_file(s_client client)
{
  int			nb_octel_read;
  int			open_file;
  char			*file;
  char			buffer[BUFF_MAX];

  nb_octel_read = 0;
  open_file = 0;
  file = extrat_path(client.cmd);
  if ((open_file = open(file, O_RDWR)) == -1)
    {
      my_putstr("Cant send the file\n");
      my_recv(client.server_socket, "Error", 5, (int)NULL);
      xfree(file);
      return (0);
    }
  send_struct(file, client);
  while ((nb_octel_read = read(open_file, buffer, BUFF_MAX)) > 0)
    my_send(client.server_socket, buffer, nb_octel_read, (int)NULL);
  if (nb_octel_read == -1)
    my_putstr("Error during transfert\n");
  close(open_file);
  return (1);
}

void			put_file_c(s_client client)
{
  char			buff[BUFF_MAX];
  int			nb_read;

  nb_read = 0;
  if (verif_arguments(client.cmd) == -1)
    my_putstr("Put: specify correct file name\n");
  else
    {
      my_send(client.server_socket, client.cmd,
	      my_strlen(client.cmd), (int)NULL);
      if (prepar_transfert(client) == 1)
	{
	  send_the_file(client);
	  nb_read = my_recv(client.server_socket, buff, BUFF_MAX, (int)NULL);
	  buff[nb_read] = '\0';
	  my_putstr(buff);
	}
    }
}
