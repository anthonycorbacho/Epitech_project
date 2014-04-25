
#ifndef __PREPROCESSY_H__
#define __PREPROCESSY_H__

/*
** Removes useless spaces ans tabs
** Replaces the tilds where it has to be
*/
char			**preprocess_expr(char **s, t_list **my_environ);

/*
** Parses a command line
** Returns a char ** containing the strings using the redirectors 
** operators as separators
** the result is in reverse order
*/
char			**command_parser(char *s);

/*
** Checks if the command is valid
** Returns 1 if success, 0 otherwise
*/
int			check_command_validity(char **command);

/*
** Returns a copy of the redirection operator
** and new point points after the redirec operator
*/
char			*find_first(char *s, char **new_pos);

/*
** Replace the tild by the HOME value
** frees the or var if a tild is present
*/
char			*replace_tilds(char *cmd, t_list **my_environ);

/*
** Removes all unnecessary spaces and tabs
*/
char			*remove_spaces_and_tabs(char *s);

int			check_command_validity(char **command);

#endif
