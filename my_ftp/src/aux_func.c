/*
** aux_func.c for aux in /home/corbac_b/My Dropbox/epitech/C/my_script/src
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 19:29:15 2010 anthony1 corbacho
** Last update Tue Feb 23 16:47:46 2010 anthony1 corbacho
*/

#include		"header_client.h"
#include		"header_server.h"

int			my_strncmp_(char *s1, char *s2, int n)
{
  int			i;

  if (n == 0)
    return (0);
  i = 1;
  while (*s1 == *s2 && s1 != '\0' && i < n)
    {
      s1++;
      s2++;
      i++;
    }
  return (*s1 - *s2);
}
