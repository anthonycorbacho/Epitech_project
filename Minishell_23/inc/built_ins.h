

#ifndef __BUILT_INS_H__
# define __BUILT_INS_H__

/*
**Built in structure
*/
typedef struct s_built
{
  char		*name;			/*Name of the built in func*/
  int		ac;			/*Nb of args of the built in*/
  int		(*func_builtin)();	/*Function pointer on the built-in*/
}		t_built;

extern t_built	builtins[];

/*
**Error prototypes
*/
#define BT_IN_CD_TOO_MANY_ARGS "Too many arguments\n"
#define BT_IN_CD_NO_SUCH_FILE ": No such file or directory\n"
#define SETENV_BAD_USAGE "Setenv error. Usage: setenv varname value\n"
#define TOO_FEW_ARGS "Too_few_args"
#define TOO_MANY_ARGS "Too many args\n"
/*
**Built ins prototypes
*/
int			built_in_cd(char *, t_list **);
int			built_in_setenv(char *, t_list **);
int			built_in_unsetenv(char *, t_list **);
int			built_in_env(char *, t_list **);
int			built_in_exit();
int			built_in_pwd();
void			too_few_args(char *);
/*
** Checks if the command is a built in
** If yes, it execs it
** Otherwise it returns -1
*/
int		exec_built_in(char *command, t_list **my_environ);
#endif
