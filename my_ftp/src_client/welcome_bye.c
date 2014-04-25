/*
** welcome_bye.c for welcome or exit msg in /home/anthony/Projet/my_ftp/src_client
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb 23 22:30:44 2010 anthony1 corbacho
** Last update Wed Mar 10 15:05:18 2010 anthony1 corbacho
*/

#include		<time.h>
#include		"header_client.h"

char			*current_time()
{
  time_t		clock;

  time(&clock);
  return (ctime(&clock));
}

void			welcome_client()
{
  my_putstr("\033[34m");
  my_putstr("\n\tMy_ftp: Client\n");
  my_putstr("Connection etablished the ");
  my_putstr(current_time());
  my_putstr("\033[37m");
  my_putchar('\n');
}

void			good_bye_client()
{
  my_putchar('\n');
  my_putstr("\033[34m");
  my_putstr("Connection closed the ");
  my_putstr(current_time());
  my_putstr("\033[37m");
  my_putchar('\n');
}
