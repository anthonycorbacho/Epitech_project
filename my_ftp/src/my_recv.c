/*
** my_recv.c for recv for read in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Sun Feb 28 23:33:26 2010 anthony1 corbacho
** Last update Fri Mar 12 11:23:06 2010 anthony1 corbacho
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<errno.h>
#include		<string.h>
#include		"header_client.h"
#include		"header_server.h"

ssize_t			my_recv(int s, void *buf, size_t len, int flags)
{
  ssize_t		size;

  if ((size = recv(s, buf, len, flags)) < 0)
    {
      if (size == -1 && errno == EAGAIN)
	my_putstr("Time OUT\n");
      else
	my_putstr("Disconnection.\n");
      close(s);
      exit(0);
    }
  return (size);
}
