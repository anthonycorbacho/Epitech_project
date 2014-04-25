/*
** str_utils.c for str utils in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 16:55:21 2010 mathieu1 lornac
** Last update Fri Apr 16 17:58:40 2010 damien1 coppel
*/

#include <sys/types.h>

#include "lstr.h"
#include "lxsys.h"

#include "str_utils.h"

/*
** Mallocs a new string and concatenates a \n
** liberates the string given in parameter
*/
char		*add_bn(char *s)
{
  char		*ret;

  ret = xmalloc(sizeof(*ret) * (my_strlen(s) + 2));
  my_strcpy(ret, s);
  my_strcat(ret, "\n");
  xfree(s);
  return (ret);
}

/*
** removes the last char if it is a backslash n
*/
char		*del_bn(char *s)
{
  if (s[my_strlen(s) - 1] == '\n')
    s[my_strlen(s) - 1] = 0;
  return (s);
}

/*
** Function debug pour TELNET /!\
*/
char		*del_bn_2(char *s)
{
  s[my_strlen(s) - 2] = 0;
  return (s);
}

int		cat_virgule(char *buffer, int doit)
{
  if (doit)
    my_strcat(buffer, ",");
  return (1);
}

/*
** Mallocs a new string
** Concatenates s1 and s2
** Liberates s1 and s2
*/
char		*dupcat(char *s1, char *s2)
{
  char		*ret;
  int		len1;
  int		len2;

  if (s1)
    len1 = my_strlen(s1);
  else
    len1 = 0;
  if (s2)
    len2 = my_strlen(s2);
  else
    len2 = 0;
  ret = xmalloc(sizeof(*ret) * (len1 + len2 + 1));
  if (s1)
    my_strcpy(ret, s1);
  else
    *ret = 0;
  if (s2)
    my_strcat(ret, s2);
  free(s1);
  free(s2);
  return (ret);
}
