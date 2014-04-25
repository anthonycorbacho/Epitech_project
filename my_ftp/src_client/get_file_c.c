/*
** get_file_c.c for get the file in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/src_client
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Mar  8 18:28:54 2010 anthony1 corbacho
** Last update Wed Mar 10 13:57:56 2010 anthony1 corbacho
*/
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"header_client.h"

void			send_result(int oct)
{
  if (oct == -1)
    my_putstr("410 Error during tansfert\n");
  else
    my_putstr("200 Transfret done\n");
}

void			get_transfert(s_client client, char *file)
{
  int			fd;
  int			size;
  struct stat		st;
  int			octel;
  char			buff[BUFF_UP];

  octel = 0;
  if ((fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 755)) == -1)
    {
      my_putstr("450 Impossible to create file\n");
      xfree(file);
      return ;
    }
  my_recv(client.server_socket, &st, sizeof(st), (int)NULL);
  size = st.st_size;
  while (size > 0)
    {
      octel = my_recv(client.server_socket, buff, BUFF_UP, (int)NULL);
      xwrite(fd, buff, octel);
      size = size - octel;
    }
  close(fd);
  xfree(file);
  send_result(octel);
}

void			get_file_c(s_client client)
{
  char			*file;
  char			buff[BUFF_MAX];
  int			total;

  total = 0;
  my_send(client.server_socket, client.cmd, my_strlen(client.cmd), (int)NULL);
  total = my_recv(client.server_socket, buff, BUFF_MAX, (int)NULL);
  buff[total] = '\0';
  if (my_strcmp(buff, "400") != 0)
  {
    file = extrat_path(buff);
    get_transfert(client, file);
    my_memset(buff, 0, BUFF_MAX);
  }
  my_memset(client.cmd, 0, BUFF_MIN);
}
