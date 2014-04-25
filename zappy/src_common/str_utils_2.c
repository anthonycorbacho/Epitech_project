/*
** str_utils_2.c for str in /home/matt/work/proj/zappy/src_server
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Mon Apr 19 13:29:57 2010 mathieu1 lornac
** Last update Mon Apr 19 13:31:35 2010 mathieu1 lornac
*/

#include <sys/types.h>

#include "lstr.h"
#include "lxsys.h"

#include "str_utils.h"

/*
** Concat s2 to s1 and returns a pointer on the end of s1
*/
char		*my_strcat_back(char *s1, char *s2)
{
  while (*s1)
    s1++;
  while (*s2)
    {
      *s1 = *s2;
      s1++;
      s2++;
    }
  *s1 = *s2;
  return (s1);
}
