/*
** my_strcpy.c for my_strcpy in /home/corbac_b/work/Jour_06
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Oct 12 08:57:50 2009 anthony1 corbacho
** Last update Mon Oct 12 10:34:52 2009 anthony1 corbacho
*/

#include	"my.h"

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
      if (src[i] == '\0')
	dest[i] = '\0';
    }
  return (dest);
}
