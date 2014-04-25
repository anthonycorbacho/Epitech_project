/*
** func_file.c for file function in /home/corbac_b/My Dropbox/epitech/C/my_script/src
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 17:27:23 2010 anthony1 corbacho
** Last update Sat Feb 13 18:18:42 2010 anthony1 corbacho
*/

/*
** Les includes
*/
#include	<string.h>
#include	<time.h>
#include	"header_script.h"

extern t_script	script;

/*
** Function for get current time when this func is call
*/
char		*current_time()
{
  time_t	clock;

  time(&clock);
  return (ctime(&clock));
}

/*
** Function for open the specifial file
** control if -a exist and open whith a option
*/
void		open_path(char *link)
{
  if (script.tab_argument[0] == '1')
    {
      if ((script.file_open = fopen(link, "a")) == 0)
	my_erno(2, link);
    }
  else
    {
      if ((script.file_open = fopen(link, "w")) == 0)
	my_erno(2, link);
    }
}
