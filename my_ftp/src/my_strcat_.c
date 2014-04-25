/*
** my_strcat_.c for my_strcat2 in /home/corbac_b/My Dropbox/epitech/C/my_ftp/ver1.0
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Mar  9 13:24:13 2010 anthony1 corbacho
** Last update Fri Mar 12 12:02:59 2010 anthony1 corbacho
*/

#include	"header_server.h"

char		*my_strcat_(char *str1, char *str2)
{
  int		i;
  int		a;

  i = 0;
  a = 0;
  while (str1[i] != '\0')
    i++;
  while (str2[a] != '\0')
    {
      str1[i] = str2[a];
      i++;
      a++;
    }
  str1[i] = '\0';
  return (str1);
}
