/*
** my_script.c for my_script in /home/corbac_b/My Dropbox/epitech/C/my_script
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 19:12:21 2010 anthony1 corbacho
** Last update Mon Feb 15 14:26:23 2010 anthony1 corbacho
*/

#include		"header_script.h"

t_script		script;

int			main(int argc, char **argv)
{
  pid_t			pid;
  char			*file;
  int			master;
  t_termios		term;
  t_winsize		win;

  master = 0;
  signal(SIGCHLD, sigchld);
  file = argv[check_arguments(argc, argv) - 1];
  if (my_strcmp(file, "./my_script") == 0 ||
      my_strncmp_(file, "-", 1) == 0)
    file = "typescript";
  init_termios(&term);
  init_winsize(&win);
  open_path(file);
  if ((pid = my_forkpty(&master, NULL, &term, &win)) < 0)
    {
      fclose(script.file_open);
      return (0);
    }
  else
    execute_command(pid, master, file);
  return (1);
}
