/*
** lstr.h for header in /home/lornac_a
**
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
**
** Started on  Mon Oct 29 17:12:47 2007 mathieu1 lornac
** Last update Thu Feb 25 10:58:08 2010 mathieu1 lornac
*/

#ifndef __LSTR_H__
# define __LSTR_H__

/*
** This file was automatically generated
** on Wed Dec  2 15:18:53 2009
*/


/*
** charpp_dup.c
*/
char			**dup_charpp(char **t);

/*
** counting.c
*/
/*
**Counts the number of occurences of the char in the base in the str s
*/
int			my_chars_count(char *base, char *s);

/*
** error_puts.c
*/
/*
**Writes a char on the error output 
*/
void			my_putchar_e(char c);
/*
**Writes a string on the error output 
*/
void			my_putstr_e(char *s);

/*
** frees.c
*/
/*
**Completely free a char**
*/
void			free_charpp(char **t);

/*
** get_first_char.c
*/
char			*get_first_alpha_char(char *s);
char			*get_first_nonalpha_char(char *s);

/*
** get_in_base.c
*/
char			*get_first_in_base(char *s, char *base);
char			*get_last_in_base(char *s, char *base);
char			*skip_space_and_tab(char *s);

/*
** is_minus_plus.c
*/
int			is_minusplus(char *c);

/*
** my_char_is.c
*/
int			my_char_isalpha(char s);
int			my_char_isnum(char s);
int			my_char_isprintable(char str);
int			my_char_is_num_or_signe(char c);
int			my_char_is_in_base(char c, char *base);

/*
** my_puts_nb.c
*/
int			to_continuemyputnbr(int nb);
int			my_put_nbr(int nb);

/*
** my_rev_str.c
*/
char			*my_revstr(char *str);

/*
** my_shift_left.c
*/
/*
**Shifts a string n chars to the left
*/
char			*shift_left(char *s, int n);

/*
** my_sprintf.c
*/
char			*my_sprintf(int nb);

/*
** my_str_is.c
*/
int			my_str_isalpha(char *str);
int			my_str_isnum(char *str);
int			my_str_isnum_signed(char *str);
int			my_str_islower(char *str);
int			my_str_isupper(char *str);
int			my_str_isprintable(char *str);

/*
** my_str_is2.c
*/
int			my_str_is_in_base(char *s, char *base);

/*
** my_str_sep.c
*/
/*
**Parses a chain with the specified delimiters
**Allocates a copy of the chains
*/
char			**my_str_sep_dup(char *s, char *delimiters);
/*
**Parses a chain with the specified delimiters
**Doesn't make a copy of the chains
**modifies the original chain
**Size has to be modified
*/
char			**my_str_sep(char *s, char *delimiters);

/*
** my_str_to_wortab.c
*/
int			my_str_to_wordtab_count(char *str);
char			**my_str_to_wordtab(char *str);
int			my_show_to_wordtab(char **tab);

/*
** my_strcapitalizes.c
*/
char			*my_strupcase(char *str);
char			*my_strlowcase(char *str);
char			*my_strcapitalize(char *str);

/*
** my_strcats.c
*/
char			*my_strcat(char *str1, char *str2);
char			*my_strncat(char *str1, char *str2, int n);
int			my_strlcat(char *str1, char *str2, int l);

/*
** my_strcmps.c
*/
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int n);

/*
** my_strcpys.c
*/
char			*my_strcpy(char *dest, char *src);
char			*my_strncpy(char *dest, char *src, int n);
char			*my_strdup(char *str);

/*
** Cleans a string 
** replaces tabs by spaces, removes contiguous spaces
** removes extreme postions spaces
*/
char			*my_str_epure(char *s);

/*
** my_strlen.c
*/
int			my_strlen(char *str);
int			my_charpp_len(char **s);

/*
** my_strputs.c
*/
void			my_putchar(char c);
int			my_putstr(char *str);

/*
** my_strstr.c
*/
char			*my_strstr(char *str, char *to_find);

/*
** str_extract.c
*/
char			*get_last_part(char *name, char delimiter);
char			*cut_last_part(char *path, char delimiter);
/*                                                                                                    
**Allocates a new string without the characters encountered                                           
** before the first occurence of the delimiter                                                        
**If no delimiter is present, it returns NULL
*/
char			*cut_first_part(char *s, char *delimiters);
char			*get_first_part(char *s, char *delimiters);

#endif
