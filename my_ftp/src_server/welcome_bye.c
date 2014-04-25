/*
** welcome_bye.c for welcome & bye in /home/anthony/Projet/my_ftp
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 24 16:42:50 2010 anthony1 corbacho
** Last update Wed Feb 24 16:59:09 2010 anthony1 corbacho
*/

#include		<time.h>
#include		"header_server.h"

char			*current_time()
{
  time_t		clock;

  time(&clock);
  return (ctime(&clock));
}

void			put_server_started()
{
  my_putstr("Server started the ");
  my_putstr(current_time());
  my_putchar('\n');
}

void			good_bye_server()
{
  my_putstr("\nServer done the ");
  my_putstr(current_time());
  my_putchar('\n');
}
