/*
** func_control_2.c for control 2 in /home/corbac_b/My Dropbox/epitech/C/my_script
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb 15 02:21:09 2010 anthony1 corbacho
** Last update Mon Feb 15 14:25:41 2010 anthony1 corbacho
*/

#include		"header_script.h"

extern t_script		script;

int			parsing_arg(char **arg)
{
  int			cpt;

  cpt = 1;
  while (arg[cpt] != '\0' && arg[cpt][0] == '-')
    cpt++;
  return (cpt);
}

int		calculate_len_cmd(int cpt, char **arg)
{
  int		len;

  len = 0;
  while (arg[cpt] != '\0')
    {
      len = len + strlen(arg[cpt]) + 1;
      cpt++;
    }
  return (len);
}

void			add_cmd(char **arg, int cpt2, char *cmd)
{
  int			j;
  int			k;

  j = 0;
  k = 0;
  while (arg[cpt2] != '\0')
    {
      while (arg[cpt2][j] != '\0')
	cmd[k++] = arg[cpt2][j++];
      j = 0;
      cpt2++;
      if (arg[cpt2] != '\0')
	cmd[k++] = ' ';
    }
  cmd[k] = '\0';
  script.cmd = cmd;
}
