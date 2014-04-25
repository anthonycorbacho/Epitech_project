/*
** commands.h for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 18:13:22 2010 damien1 coppel
** Last update Tue Apr 13 11:48:23 2010 damien1 coppel
*/

#ifndef __COMMANDS_SRV_H__
#define __COMMANDS_SRV_H__

/*
** Define type for commands
*/
struct		s_command
{
  char		*name;
  int		len_name;
  int		time;
  char           *(*ptr_func)();
};
typedef struct s_command t_command;

/*
** The commands time and function
*/
extern t_command lst_cmd[];
extern t_command lst_cmd_gr[];

#endif /* __COMMANDS_SRV_H__ */
