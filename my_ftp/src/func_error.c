/*
** func_error.c for function_error in /home/corbac_b/My Dropbox/epitech/C/my_script/src
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 15:46:44 2010 anthony1 corbacho
** Last update Tue Feb 23 19:13:03 2010 anthony1 corbacho
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"header_client.h"

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
  if (code == 2)
    {
      my_putstr_error(str);
      my_putstr_error(" : Cant open file.\n");
    }
  if (code == 3)
    my_putstr_error(str);
   exit(1);
}
