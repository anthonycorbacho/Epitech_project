/*
** main.c for main for server in /home/anthony/Projet/my_ftp/src_server
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 24 15:26:38 2010 anthony1 corbacho
** Last update Wed Mar 10 13:53:17 2010 anthony1 corbacho
*/

#include		"header_server.h"

int			verif_argument(int ac, char **ag)
{
  int			cpt;
  int			verif_port;

  if (ac != 2)
    return (0);
  cpt = 0;
  verif_port = 0;
  while (ag[1][cpt])
    {
      if (ag[1][cpt] < 48 || ag[1][cpt] > 57)
	return (0);
      cpt++;
    }
  verif_port = my_getnbr(ag[1]);
  if (verif_port > 65535 || verif_port < 0)
    my_erno(3, "Invalid port number !\n");
  if (verif_port < 1025)
    my_putstr("FTP Warnning: Selected port may be cause problems\n");
  return (1);
}

int			main(int argc, char **argv)
{

  if (verif_argument(argc, argv) == 0)
    my_erno(3, "my_ftp: usage server [port]\n");
  start_server(argv);
  return (1);
}
