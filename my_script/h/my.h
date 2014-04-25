/*
** my.h for my_lib_h in /nfs/export/work/Jour_09/exo01
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Fri Oct 16 11:35:54 2009 anthony1 corbacho
** Last update Sun Nov 29 20:02:20 2009 anthony1 corbacho
*/

#ifndef		__MY_LIB_H__
#define		__MY_LIB_H__

void		my_putchar(char c);
int		my_isneg(int n);
int		my_put_nbr(int nb);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
/*
void		my_sort_int_tab(int *tab, int size);
*/
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_revstr(char *str);    
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showstr(char *str);
int		my_showmem(char *str, int size);
char		*my_strcat(char *str1, char *str2);
char		*my_strncat(char *str1, char *str2, int n);
int		my_strlcat(char *str1, char *str2, int n);
int		my_getnbr_base(char *str, char *base);
int		my_putchar_base(int nbr, char *base);
char		**my_str_to_wordtab(char *str);
char		*my_strdup(char *str);
int		my_putchar_base(int nbr, char *base);

#endif		/* __MY_LIB_H__ */
