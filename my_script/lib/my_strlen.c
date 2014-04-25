/*
** my_strlen.c for my_strlen in /home/corbac_b/work/lib
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Oct 14 09:09:34 2009 anthony1 corbacho
** Last update Tue Feb  9 00:18:16 2010 anthony1 corbacho
*/

#include	"my.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    { 
      i++;
    }
  return (i);
}
