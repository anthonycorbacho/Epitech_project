/*
** my_strcmp.c for my_strcmp in /home/corbac_b/work/Jour_06
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Oct 12 16:13:58 2009 anthony1 corbacho
** Last update Tue Oct 13 17:17:58 2009 anthony1 corbacho
*/

#include	"my.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;
  int		result;

  i = 0;
  result = 1;
  while (s1[i] && s2[i] && result == 1)
    {
      if (s1[i] != s2 [i])
	{
	  result = 0;
	}
      else
	{
	  i = i + 1;
	}
    }
  return (s1[i] - s2[i]);
}
