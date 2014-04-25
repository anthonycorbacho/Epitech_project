/*
** my.h for header in /home/coppel_a
**
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
**
** Started on  Mon Oct 29 17:12:47 2007 damien1 coppel
** Last update Mon Oct 19 14:32:26 2009 damien1 coppel
*/

#ifndef			__MY_H__
# define		__MY_H__

/*
** This file was automatically generated
** on Mon Oct 19 14:27:32 2009
*/


/*
** my_find_prime_sup.c
*/
int			my_find_prime_sup(int nb);

/*
** my_getnbr.c
*/
int			my_getnbr(char *str);

/*
** my_is_prime.c
*/
int			my_is_prime(int nombre);

/*
** my_isneg.c
*/
int			my_isneg(int n);

/*
** my_power_rec.c
*/
int			my_power_rec(int nb, int power);

/*
** my_put_nbr.c
*/
int			my_put_nbr(int nb);

/*
** my_putchar.c
*/
void			my_putchar(char c);

/*
** my_putnbr_base.c
*/
int			my_putnbr_base(int nbr, char *base);

/*
** my_putstr.c
*/
int			my_putstr(char *str);

/*
** my_revstr.c
*/
char			*my_revstr(char *str);

/*
** my_show_to_wordtab.c
*/
int			my_show_to_wordtab(char **tab);

/*
** my_showstr.c
*/
int			my_showstr(char *str);

/*
** my_sort_int_tab.c
*/
void			my_sort_int_tab(int *tab, int size);

/*
** my_square_root.c
*/
int			my_square_root(int nb);

/*
** my_str_isalpha.c
*/
int			my_str_isalpha(char *str);

/*
** my_str_islower.c
*/
int			my_str_islower(char *str);

/*
** my_str_isnum.c
*/
int			my_str_isnum(char *str);

/*
** my_str_isprintable.c
*/
int			my_str_isprintable(char *str);

/*
** my_str_isupper.c
*/
int			my_str_isupper(char *str);

/*
** my_str_to_wordtab.c
*/
int			is_alphanum_stw(char c);
int			get_nb_line_stw(char *str);
char			*get_next_alphanum_stw(char *str);
int			my_wordlen_stw(char *str);
char			**my_str_to_wordtab(char *str);

/*
** my_strcapitalize.c
*/
char			*my_strcapitalize(char *str);

/*
** my_strcat.c
*/
char			*my_strcat(char *str1, char *str2);

/*
** my_strcmp.c
*/
int			my_strcmp(char *s1, char *s2);

/*
** my_strcpy.c
*/
char			*my_strcpy(char *dest, char *src);

/*
** my_strdup.c
*/
char			*my_strdup(char *str);

/*
** my_strlcat.c
*/
int			my_strlcat(char *str1, char *str2, int l);

/*
** my_strlen.c
*/
int			my_strlen(char *str);

/*
** my_strlowcase.c
*/
char			*my_strlowcase(char *str);

/*
** my_strncat.c
*/
char			*my_strncat(char *str1, char *str2, int n);

/*
** my_strncmp.c
*/
int			my_strncmp(char *s1, char *s2, int n);

/*
** my_strncpy.c
*/
char			*my_strncpy(char *dest, char *src, int n);

/*
** my_strstr.c
*/
int			check_size(int size1, int size2);
char			*my_strstr(char *str, char *to_find);

/*
** my_strupcase.c
*/
char			*my_strupcase(char *str);

/*
** my_swap.c
*/
int			my_swap(int *a, int *b);

#endif			/* __MY_H__ */
