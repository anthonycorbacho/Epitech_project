/*
** str_utils.h for str in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Mar 19 16:56:00 2010 mathieu1 lornac
** Last update Mon Apr 19 13:33:49 2010 mathieu1 lornac
*/

#ifndef __STR_UTILS_H__
#define __STR_UTILS_H__

/*
** Mallocs a new string and concatenates a \n
** liberates the string in parameter
*/
char		*add_bn(char *s);

/*
** removes the last char
*/
char		*del_bn(char *s);

/*
** Function debug pour TELNET /!\
*/
char		*del_bn_2(char *s);


int		cat_virgule(char *buffer, int doit);

/*
** Mallocs a new string
** Concatenates s1 and s2
** Liberates s1 and s2
*/
char		*dupcat(char *s1, char *s2);

/*
** Concat s2 to s1 and returns a pointer on the end of s1
*/
char		*my_strcat_back(char *s1, char *s2);

#endif /*__STR_UTILS_H__*/
