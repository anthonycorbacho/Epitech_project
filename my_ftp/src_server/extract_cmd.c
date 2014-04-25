/*
** extract_cmd.c for extract the file in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0/src_client
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Mar  8 18:04:47 2010 anthony1 corbacho
** Last update Tue Mar  9 13:37:07 2010 anthony1 corbacho
*/

#include		"header_server.h"

char			*extrat_cmd(char *cmd)
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
