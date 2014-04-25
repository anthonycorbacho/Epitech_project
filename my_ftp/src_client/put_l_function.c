/*
** put_l_function.c for l function in /home/anthony/Projet/my_ftp/src_client
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 24 00:02:57 2010 anthony1 corbacho
** Last update Fri Mar  5 13:43:43 2010 anthony1 corbacho
*/

#include		<sys/types.h>
#include		<sys/wait.h>
#include		<unistd.h>
#include		"header_client.h"

void			put_lpwd()
{
  pid_t			pid;

  pid = fork();
  if (pid == -1)
    my_erno(3, "Lpwd Failled\n");
  else
    {
      if (pid == 0)
	execlp("pwd", "pwd", NULL);
      else
	wait(NULL);
    }
}

void			put_lls()
{
  pid_t			pid;

  pid = fork();
  if (pid == -1)
    my_erno(3, "Lls Failled\n");
  else
    {
      if (pid == 0)
	execlp("ls", "ls", "-la", NULL, NULL);
      else
	wait(NULL);
    }
}

char			*extrat_path(char *cmd)
{
  int			cpt;
  int			i;
  char			*path;
  int			i2;

  cpt = 3;
  i = 4;
  i2 = 0;
  while (cmd[cpt])
    cpt++;
  path = xmalloc((cpt - 3) * sizeof(path));
  while (i < cpt)
    {
      path[i2] = cmd[i];
      i++;
      i2++;
    }
  path[i2] = '\0';
  return (path);
}

void			put_lcd(char *cmd)
{
  char			*the_cd;

  if (my_strlen(cmd) == my_strlen("lcd"))
    my_putstr("Lcd need directory\n");
  else
    {
      the_cd = extrat_path(cmd);
      if (chdir(the_cd) == -1)
	my_putstr("No such file or directory\n");
      xfree(the_cd);
    }
}

