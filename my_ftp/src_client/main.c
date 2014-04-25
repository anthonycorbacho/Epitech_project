/*
** main.c for main for client in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb 23 16:45:48 2010 anthony1 corbacho
** Last update Tue Mar  9 11:24:14 2010 anthony1 corbacho
*/

#include		<signal.h>
#include		"header_client.h"

void		put_usage()
{
  my_putstr("my_FTP: Usage client [ip] [port]\n");
}

int			verif_ip(char *ip)
{
  int			cpt;
  int			dot;

  if (my_strcmp(ip, "localhost") == 0)
    return (1);
  cpt = 0;
  dot = 0;
  while (ip[cpt])
    {
      if (ip[cpt] == '.')
	dot++;
      cpt++;
    }
  if (dot != 3)
    return (0);
  cpt = 0;
  while (ip[cpt])
    {
      if ((ip[cpt] < 48 || ip[cpt] > 57) &&
	  ip[cpt] != '.')
	return (0);
      cpt++;
    }
  return (1);
}

int			verif_port(char *port)
{
  int			cpt;
  int			verif_port;

  cpt = 0;
  verif_port = 0;
  while (port[cpt])
    {
      if (port[cpt] < 48 || port[cpt] > 57)
	return (0);
      cpt++;
    }
  verif_port = my_getnbr(port);
  if (verif_port > 65535)
    my_erno(3, "Invalid port number !\n");
  if (verif_port < 1025)
    my_putstr("FTP Warnning: Selected port may be cause problems\n");
  return (1);
}

int			cheack_arguments(int ac, char **argv)
{
  if (ac < 2 || ac > 3)
    return (0);
  if (verif_ip(argv[1]) == 0)
    return (0);
  if (verif_port(argv[2]) == 0)
    return (0);
  return (1);
}

int			main(int argc, char **argv)
{

  if (cheack_arguments(argc, argv) == 0)
    {
      put_usage();
      return (0);
    }
  lunch_client(argv);
  return (1);
}
