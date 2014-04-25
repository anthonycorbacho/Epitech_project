/*
** func_inc_terminal.c for terminal add in /home/corbac_b/My Dropbox/epitech/C/my_script
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Wed Feb 10 17:38:40 2010 anthony1 corbacho
** Last update Mon Feb 15 14:14:42 2010 anthony1 corbacho
*/

#include		"header_script.h"

extern t_script		script;

void			sigchld()
{
  int			status;

  status = 0;
  wait(&status);
  script.halt = 1;
}

/*
** Writte bottom header and close file.
** and free the cmd if cmd exist
*/
void			good_bye(char *link)
{
  if (script.tab_argument[2] != '1')
    {
      xwrite(1, "\nScript done, output file is ", 29);
      fwrite("\nScript done on ", 1, 16, script.file_open);
      xwrite(1, link, my_strlen(link));
      fwrite(current_time(), 1, my_strlen(current_time()), script.file_open);
      xwrite(1, "\n", 1);
    }
  tcsetattr(0, TCSANOW, &script.old);
  if (script.cmd != 0)
    free(script.cmd);
  fclose(script.file_open);
  exit(1);
}

/*
** Test and read & write the buffer to the file.
** If fd == 0 stop the execution, and call func goodbye
*/
void			include_to_terminal(int master, fd_set *readf,
					    char *link)
{
  char			my_buffer[512];
  int			fd;

  if (FD_ISSET(0, &(*readf)))
    {
      if ((fd = read(0, my_buffer, sizeof (my_buffer))) < 0)
	my_erno(3, "read error ISSET 0\n");
      if (fd == 0)
	good_bye(link);
      write(master, my_buffer, fd);
    }
  if (FD_ISSET(master, &(*readf)))
    {
      if ((fd = read(master, my_buffer, sizeof (my_buffer))) < 0)
	my_erno(3, "read error master");
      if (fd == 0)
	good_bye(link);
      write(1, my_buffer, fd);
      fwrite(my_buffer, 1, fd, script.file_open);
      if (script.tab_argument[1] == '1')
	fwrite(my_buffer, 1, fd, script.file_open);
    }
}
