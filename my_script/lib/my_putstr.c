/*
** my_putstr.c for my_putstr in /home/corbac_b/work/lib
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Oct 14 09:08:48 2009 anthony1 corbacho
** Last update Tue Oct 20 14:39:03 2009 anthony1 corbacho
*/

#include	"my.h"

int		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
  {
    my_putchar(str[i]);
    i++;
  }
  return (1);
}
