/*
** read_write_sock.c for read and write in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri Feb 26 11:30:11 2010 anthony1 corbacho
** Last update Tue Mar  9 11:21:50 2010 anthony1 corbacho
*/

#include			<unistd.h>
#include			"header_client.h"
#include			"header_server.h"

void				write_sock(char *cmd, int socket)
{
  int				len_cmd;
  int				fd_write;
  int				count;

  len_cmd = my_strlen(cmd);
  fd_write = 0;
  count = 0;
  while (count != len_cmd)
    {
      fd_write = write(socket, cmd, len_cmd);
      if (fd_write == -1)
	{
	  my_putstr("Error write");
	}
      count =+ fd_write;
    }
}

void				read_sock(char *cmd,
					  int socket_rec)
{
  int				count;
  int				len_cmd;
  int				fd_read;

  len_cmd = my_strlen(cmd);
  fd_read = 0;
  count = 0;
  while (count < len_cmd)
    {
      fd_read = read(socket_rec, &cmd, len_cmd);
      if (fd_read == -1)
	my_erno(3, "Read_sock failled\n");
      count =+ fd_read;
    }
}
