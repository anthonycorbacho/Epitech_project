/*
** my_send.c for send packets in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Sun Feb 28 23:20:00 2010 anthony1 corbacho
** Last update Tue Mar  9 11:20:41 2010 anthony1 corbacho
*/

#include		<sys/types.h>
#include		<unistd.h>
#include		<sys/socket.h>
#include		<stdlib.h>
#include		<time.h>
#include		"header_client.h"
#include		"header_server.h"

ssize_t			my_send(int s, void *msg, size_t len, int flags)
{
  ssize_t		result;
  int			nb;

  if (s != -1)
    {
      if ((result = send(s, msg, len, flags)) == -1)
	{
	  nb = 0;
	  while ((result = send(s, msg, len, flags)) < 0 && nb < 5)
	    {
	      sleep(1);
	      nb++;
	    }
	  if (nb == 5)
	    {
	      close(s);
	      exit(1);
	    }
	}
      return (result);
    }
  return (0);
}
