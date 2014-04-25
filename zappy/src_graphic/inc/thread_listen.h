/*
** thread_listen.h for zappy in /home/matias/Dropbox/zappy_2012s_coppel_a
** 
** Made by matias1 hastaran
** Login   <matias@epitech.net>
** 
** Started on  Wed Apr  7 11:09:06 2010 matias1 hastaran
** Last update Tue Apr 20 09:33:33 2010 anthony1 corbacho
*/

#ifndef		__THREAD_LISTEN_H__
#define		__THREAD_LISTEN_H__

#include "structure_server.h"

typedef struct	s_func
{
  char		*func;
  int		(*ptr_func)(char *, t_elem *);
}		t_func;

int		msz(char *, t_elem *);
int		sgt(char *, t_elem *);
int		bct(char *, t_elem *);
int		tna(char *, t_elem *);
int		pnw(char *, t_elem *);
int		ppo(char *, t_elem *);
int		plv(char *, t_elem *);
int		pdi(char *, t_elem *);
int		pic(char *, t_elem *);
int		pie(char *, t_elem *);
int		pbc(char *, t_elem *);
int		enw(char *, t_elem *);
int		eht(char *, t_elem *);
int		edi(char *, t_elem *);
int		pin(char *, t_elem *);

void		fill_cell(int, int, char **);
int		thread_listen(void *);

#endif		/* __THREAD_LISTEN_H__ */
