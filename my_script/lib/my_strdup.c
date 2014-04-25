/*
** my_strdup.c for my_strdup in /home/corbac_b/work/Jour_08
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Oct 14 21:45:56 2009 anthony1 corbacho
** Last update Thu Feb 11 00:15:06 2010 anthony1 corbacho
*/

#include	<stdlib.h>
#include	"my.h"

void            *malloc(size_t size);

char		*my_strdup(char *str)
{
  char		*newstr;
  int		lennewstr;

  lennewstr = my_strlen(str);
  newstr = malloc((lennewstr + 1) * sizeof(*newstr));
  my_strcpy(newstr, str);
  return (newstr);
}
