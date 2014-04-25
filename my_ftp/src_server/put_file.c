/*
** put_file.c for put the file in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/src_server
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Sun Mar  7 18:31:52 2010 anthony1 corbacho
** Last update Fri Mar 12 11:36:31 2010 anthony1 corbacho
*/
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"header_server.h"

char			*extrat_path(char *cmd)
{
  int			cpt;
  int			i;
  char			*path;
  int			i2;

  cpt = 3;
  i = 4;
  i2 = 0;
  while (cmd[cpt])
    cpt++;
  path = xmalloc((cpt - 3) * sizeof(path));
  while (i < cpt)
    {
      path[i2] = cmd[i];
      i++;
      i2++;
    }
  path[i2] = '\0';
  return (path);
}

void			send_result(int oct, s_server srv)
{
  if (oct == -1)
    my_send(srv.socket_client, "410 Error during tansfert\n",
	    my_strlen("410 Error during tansfert\n"), (int)NULL);
  else
    my_send(srv.socket_client, "200 Transfret done\n",
	    my_strlen("200 Transfret done\n"), (int)NULL);
}

void			start_transfert(s_server srv, char *file)
{
  int			fd;
  int			size;
  struct stat		st;
  int			octel;
  char			buff[BUFF_UP];

  octel = 0;
  if ((fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0755)) == -1)
    {
      my_send(srv.socket_client, "450 Impossible to create file\n",
	      my_strlen("450 Impossible to create file\n"), (int)NULL);
      xfree(file);
      return ;
    }
  my_recv(srv.socket_client, &st, sizeof(st), (int)NULL);
  size = st.st_size;
  my_memset(buff, 0, BUFF_UP);
  while (size > 0)
    {
      octel = my_recv(srv.socket_client, buff, BUFF_UP, (int)NULL);
      xwrite(fd, buff, octel);
      size = size - octel;
    }
  close(fd);
  send_result(octel, srv);
}

void			put_file(s_server srv)
{
  char			*file;

  file = extrat_path(srv.cmd);
  start_transfert(srv, file);
  xfree(file);
  my_memset(srv.cmd, 0, BUFF_MIN);
}
