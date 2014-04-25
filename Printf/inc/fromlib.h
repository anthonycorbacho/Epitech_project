

#ifndef __FROMLIB_H__
# define __FROMLIB_H__

/*
** This file was automatically generated
** on Tue Nov 24 10:39:42 2009
*/
typedef struct s_list
{
  void		*data;
  struct s_list	*next;
}	t_list;

/*
** fromlib1.c
*/
void			*pf_xmalloc(int size);
int			pf_char_is_in_base(char c, char *base);
char			*pf_shift_left(char *s, int n);
void			pf_putchar(char c);
int			pf_putstr(char *str);

/*
** fromlib2.c
*/
int			pf_char_isnum(char s);
int			pf_char_isprintable(char str);
char			*pf_strcpy(char *dest, char *src);
char			*pf_strncpy(char *dest, char *src, int n);
char			*pf_strdup(char *str);

/*
** fromlib3.c
*/
char			**pf_str_sep(char *s, char *delimiters);
int			pf_chars_count(char *base, char *s);
int			pf_atoi(char *a);
long long		pf_power(int nb, int p);

/*
** fromlib4.c
*/
int			pf_strcmp(char *s1, char *s2);
int			pf_strlen(char *str);
void			pf_putchar_e(char c);
void			pf_putstr_e(char *s);
t_list			*pf_insert_queue(t_list *list, t_list *elt);

/*
** fromlib5.c
*/
t_list			*pf_insert_head(t_list *list, t_list *elt);
void			pf_completely_free_list(t_list *l, void (*liberer)());
#endif
