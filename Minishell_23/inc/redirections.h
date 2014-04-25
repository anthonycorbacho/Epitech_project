
#ifndef __REDIRECTIONS_H__
#define __REDIRECTIONS_H__

typedef struct	s_redirec
{
  char		*name;
  int		(*func_op)();
}		t_redirec;

/*
** Return a pointer on the redirec function
** NULL if not found
*/
int			(*get_redirec(char *s))();

/*
** Pipe redirection
*/
int			red_pipe(int olds[2], int toyos[2], char *s);

/*
** File trunc redirection
*/
int			red_right(int olds[2], int toyos[2], char *s);

/*
** File append redirection
*/
int			red_d_right(int olds[2], int toyos[2], char *s);

/*
** Left redirection
*/
int			red_left(int olds[2], int toyos[2], char *s);

int			red_d_left(int olds[2], int toyos[2], char *s);
/*
** Init the toyos values according to the specified redirection operator
*/
int			init_toyos(char **instrucs, int i, int *toyos,
				   int *old);
/*
** Redirects the pipe
** Has to be called in a child process
** mode == 1 Dup for i + 1 instruc
** mode == 0 Dup for i - 1 instruc
*/
void			my_dup2(int mode, int toyos[2], int olds[2],
			        int (*redir)());
/*
** Calls execve if necessary
*/
void			execve_call(char **instrucs, int i,
				    t_list **my_environ);
/*
** Executes the instructions with the redirections
*/
int			create_pipes_and_exec(char **instrucs, int i,
					      t_list **my_environ, int *old);
/*
** Waits the end of the child process
** Checks how it ended
*/
void			child_control_func(pid_t id, int toyos[2], int olds[2]);
#endif
