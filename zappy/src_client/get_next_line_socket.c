/*
** get_next_line_socket.c for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Thu Apr  8 13:57:57 2010 matias1 hastaran
** Last update Sat Apr 24 15:44:44 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include "lstr.h"
#include "lmy_printf.h"
#include "lmy.h"
#include "lxsys.h"

void			init_var_gnls(int *size, char **res, int *i)
{
  *size = 256;
  *res = xmalloc((*size) * sizeof(**res));
  *i = 0;
  (*res)[0] = '\0';
}

int			gnls_is_in(char *s, char c)
{
  while (*s)
    {
      if (*s == c)
	return (1);
      s++;
    }
  return (0);
}

void			get_biger(char **res, int *size)
{
  char			*tmp;

  (*size) += (*size);
  tmp = *res;
  *res = xmalloc((*size) * sizeof(**res));
  my_strcpy(*res, tmp);
  free(tmp);
}

char			*get_next_line_socket(int cs)
{
  char			*res;
  int			size;
  int			i;
  int			j;

  init_var_gnls(&size, &res, &i);
  while (!(gnls_is_in(res, '\n')))
    {
      j = recv(cs, res + i, 1, 0);
      if (j == 0 || j == -1)
	{
	  free(res);
	  return (NULL);
	}
      i += j;
      res[i] = '\0';
      if (i == size)
	get_biger(&res, &size);
    }
  return (res);
}
