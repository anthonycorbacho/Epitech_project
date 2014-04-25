/*
** chain_receive.c for chain_receive in /home/tom/zappy
** 
** Made by thomas1 salomon
** Login   <salomo_b@epitech.net>
** Started on  Fri Apr 7 20:32:11 2010 thomas1 salomon
** Last update Tue Apr 7 20:35:38 2010 thomas1 salomon
*/

#include <stdlib.h>
#include <sys/types.h>

#include "lmy.h"
#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "ip_connection.h"
#include "ip_protocol.h"

#include "definitions.h"
#include "client.h"
#include "commands.h"
#include "str_utils.h"
#include "map.h"
#include "replicate.h"
#include "position.h"
#include "get_next_line.h"

/*
** Fonction qui interprete les reponses du serveur
** toutes les reponses ne sont pas encore gerees.
*/

int		interprete_cmd(char *cmd)
{
  if (my_strcmp(cmd, "ok") == 0)
    {
      my_printf(cmd);
      return (0);
    }
  if (my_strcmp(cmd, "ko") == 0)
    {
      my_printf(cmd);
      return (-1);
    }
  if (my_strcmp(cmd, "elevation en cours") == 0)
    {
      my_printf(cmd);
      return (0);
    }
  if (my_strncmp(cmd, "niveau actuel :", 15) == 0)
    {
      my_printf(cmd);
      return (0);
    }
  return (0);
}

/*
** Chain Receive permet de recuperer toutes les reponses du
** serveur en chaines. Cependant pour le moment qd il n'y a plus
** de reponses, la fonction attend au get_next_line
** envisager l'envoi et la reception dans 2 threads differents.
*/

int		chain_receive(int sock)
{
  char		*cmd;
  int		rslt;

  while ((cmd = get_next_line(sock)) != 0)
    {
      my_printf(cmd);
      rslt = interprete_cmd(cmd);
      if (rslt == -1)
	{
	  my_putstr_e("A command returned ko, exiting...");
	  return (-1);
	}
    }
  return (0);
}
