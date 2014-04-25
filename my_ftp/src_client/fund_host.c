/*
** fund_host.c for hostfound in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb 23 22:58:59 2010 anthony1 corbacho
** Last update Tue Feb 23 23:15:13 2010 anthony1 corbacho
*/

#include		<netdb.h>
#include		"header_client.h"

void			found_host(char *host)
{
  struct hostent	*my_host;

  if ((my_host = gethostbyname(host)) == NULL)
    my_erno(3, "Host not found \n");
}
