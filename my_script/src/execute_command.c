/*
** execute_command.c for exec the cmd in /home/corbac_b/My Dropbox/epitech/C/my_script
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 10 13:55:12 2010 anthony1 corbacho
** Last update Mon Feb 15 14:16:03 2010 anthony1 corbacho
*/

#include	<errno.h>
#include	"header_script.h"

extern t_script	script;

/*
** Function called when my_script is lunched
*/
void		welcome_msg(char *link)
{
  if (script.tab_argument[2] != '1')
    {
      xwrite(1, "Script started, output file is ", 31);
      fwrite("Script started on ", 1, 18, script.file_open);
      xwrite(1, link, my_strlen(link));
      fwrite(current_time(), 1, my_strlen(current_time()), script.file_open);
      xwrite(1, "\n", 1);
    }
}

/*
** 'Main' Function who wait switching status of multiple
** file descriptor
*/
void		loop(int master, char *link)
{
  fd_set	readf;

  welcome_msg(link);
  while (script.halt == 0)
    {
      FD_ZERO(&readf);
      FD_SET(0, &readf);
      FD_SET(master, &readf);
      if ((select(master + 1, &readf, NULL, NULL, NULL)) >= 0)
	include_to_terminal(master, &readf, link);
    }
  good_bye(link);
  exit(1);
}

/*
** Function who get the full Shell path
*/
char		*get_env_shell()
{
  extern char	**environ;
  int		cpt;
  char		*str;

  cpt = 0;
  while (environ[cpt] != 0)
    {
      if (my_strncmp_("SHELL", environ[cpt], 5 ) == 0)
	{
	  str = xmalloc(sizeof(str) * (my_strlen(environ[cpt]) + 1));
	  return (my_strcpy(str, &(environ[cpt][6])));
	}
      cpt++;
    }
  return ("/bin/sh");
}

/*
** Function who get simple shell, this function
** depended get_env_shell char* return
*/
char		*get_shell(char *env)
{
  char		*str;

  str = xmalloc(sizeof(str) * (my_strlen(env) + 1));
  return (my_strcpy(str, &(env[5])));
}

/*
** Function execute exec[lp/l] if the pid = 0 (children precess)
** Or execute the main loop
*/
int		execute_command(pid_t pid, int master, char *link)
{
  char		*env_shell;
  char		*shell;

  env_shell = get_env_shell();
  shell = get_shell(env_shell);
  if (pid == 0)
    {
      if (script.cmd != NULL)
	execlp(env_shell, shell, "-c", script.cmd, (char *)NULL);
      else
	execl(env_shell, shell, (char *)NULL);
      fclose(script.file_open);
      exit(1);
    }
  else
    loop(master, link);
  return (1);
}
