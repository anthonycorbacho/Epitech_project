/*
** s_list.h for s_list in /home/coppel_a/work/piscine/J11
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Tue Oct 20 08:59:38 2009 damien1 coppel
** Last update Tue Oct 20 09:31:35 2009 damien1 coppel
*/

#ifndef			__S_LIST_H__
# define		__S_LIST_H__

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

//typedef struct s_list t_list;

#endif			/* __S_LIST_H__ */
