/*
** lmy.h for header in /home/lornac_a
**
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
**
** Started on  Mon Oct 29 17:12:47 2007 mathieu1 lornac
** Last update Mon Oct 29 17:12:47 2007 mathieu1 lornac
*/

#ifndef __LMY_H__
# define __LMY_H__

/*
** This file was automatically generated
** on Wed Dec  9 11:29:38 2009
*/


/*
** libmy.c
*/
int			my_atoi(char *a);
long long		my_atoll(char *a);
int			my_isneg(int n);
int			my_swap(int *a, int *b);
long long		my_power(int nb, int p);
int			get_signe(char *str);
char			*get_nb_digits(char *str, int *occur);
int			my_getnbr(char *str);
void			my_sort_int_tab(int *tab, int size);
long long		determine_power(char* str, int base);

#endif
