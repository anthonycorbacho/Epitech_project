/*
** func_error.c for function_error in /home/corbac_b/My Dropbox/epitech/C/my_script/src
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 15:46:44 2010 anthony1 corbacho
** Last update Wed Feb 10 23:58:19 2010 anthony1 corbacho
*/

#include		"header_script.h"

void			my_putchar_error(char c)
{
  write(2, &c, 1);
}

int			my_putstr_error(char *str)
{
  int			cpt;

  cpt = 0;
  while (str[cpt] != '\0')
    {
      my_putchar_error(str[cpt]);
      cpt++;
    }
  return (1);
}

int			my_erno(int code, char *str)
{
  if (code == 1)
    {
      my_putstr_error("script: illegal option --");
      my_putstr_error(str);
      my_putstr_error("\nusage: script [-akq] [-t time]");
      my_putstr_error(" [file [command ...]]\n");
    }
  if (code == 2)
    {
      my_putstr_error(str);
      my_putstr_error(" : Cant open file.\n");
    }
  if (code == 3)
    my_putstr_error(str);
   exit(1);
}
