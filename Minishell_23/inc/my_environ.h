
#ifndef __MY_ENVIRON_H__
#define __MY_ENVIRON_H__

t_list			*prepare_environ();
int			my_env_cmp(char *s1, char *s2);
char			*add_equal(char *name);
char			*get_env_var_value(t_list *env, char *name);
int			set_env_var_value(t_list **my_environ, char *varname,
					  char *value);
int			unset_env_var(t_list **env, char *varname);
void			liberer_environ(t_list *my_environ);

/*
**my_environ utilities
*/
int			my_env_cmp(char *s1, char *s2);
char			*add_equal(char *name);
#endif
