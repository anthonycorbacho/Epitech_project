
#ifndef __EXECUTION_H__
# define __EXECUTION_H__

/*
** This file was automatically generated
** on Tue Nov 17 20:29:50 2009
*/


/*
** execution.c
*/
/*
**Looks for the exe in the dirs contained in the variable path
**Return NULL if it doesnt exist
*/
char			*get_exe_path(char *command, t_list **my_environ);
/*
**Executes the specified command
*/
void			executer(char *command, t_list **my_environ);

#endif
