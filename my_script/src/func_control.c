/*
** func_control.c for control arg in /home/anthony/Dropbox/epitech/C/my_script/src
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 10:13:58 2010 anthony1 corbacho
** Last update Mon Feb 15 14:16:25 2010 anthony1 corbacho
*/

#include		"header_script.h"

/*
** Check if possible cmd exist
*/
extern t_script		script;

int			find_cmd(int cpt, char **arg)
{
  int			cpt2;
  int			fic;
  int			size;

  fic = cpt;
  cpt2 = parsing_arg(arg);
  if (arg[cpt2] != '\0' && arg[cpt2 + 1] != '\0')
    {
      fic = cpt2;
      cpt2++;
      size = calculate_len_cmd(cpt2, arg);
      script.cmd = xmalloc(sizeof(*(script.cmd)) * size);
      add_cmd(arg, cpt2, script.cmd);
      fic++;
    }
  return (fic);
}

/*
** Check if the args are OK
*/
int			is_valid(char verif)
{
  if (verif == 0)
    return (0);
  if (verif == 'a')
    {
      script.tab_argument[0] = '1';
      return (1);
    }
  if (verif == 'k')
    {
      script.tab_argument[1] = '1';
      return (1);
    }
  if (verif == 'q')
    {
      script.tab_argument[2] = '1';
      return (1);
    }
  my_erno(1, "invalid argument");
  return (0);
}

int			continu_parsing(int cpt, char **arg)
{
  int			FLAG;
  int			i;

  i = 1;
  FLAG = cpt;
  while (arg[i] != '\0')
    {
      if (my_strncmp_(arg[i], "-", 1) != 0)
	{
	  FLAG = i;
	  return (FLAG);
	}
      i++;
    }
  return (FLAG);
}

/*
** Parsing the args and return cpt
*/
int			check_arguments(int nb_arg, char **argument)
{
  int			cpt;
  int			cpt_arg;
  int			flag;

  if (nb_arg == 1)
    return (1);
  cpt = 1;
  flag = continu_parsing(nb_arg, argument);
  while (cpt < nb_arg)
    {
      cpt_arg = 1;
      if (cpt < flag)
	{
	  if ((argument[cpt][0] == '-' && my_strlen(argument[cpt]) > 1))
	      while (cpt_arg < my_strlen(argument[cpt]))
		{
		  if (is_valid(argument[cpt][cpt_arg]) == 1)
		    cpt_arg++;
		  else
		    return (0);
		}
	}
      cpt++;
    }
  return (find_cmd(cpt, argument));
}
