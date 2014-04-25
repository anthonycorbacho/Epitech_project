/*
** lxsys.h for header in /home/lornac_a
**
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
**
** Started on  Mon Oct 29 17:12:47 2007 mathieu1 lornac
** Last update Wed Mar 24 11:07:53 2010 mathieu1 lornac
*/

#ifndef __LXSYS_H__
#define __LXSYS_H__

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/time.h>

/*
** xclose.c, prints a message if it fails
*/
void			xclose(int fd);

/*
** Checks dup 2 return, prints a message if it fails
*/
void			xdup2(int old, int new);

/*
** xfree.c
** Frees a single variable
*/
void			xfree(void *d);

/*
** Frees n variables
** Last argument has to be eq to (void *) -1
*/
void			xfree_n(void *a, ...);

/*
** Checks malloc return, exits if it fails
*/
void			*xmalloc(int size);

/*
** Write with a return check
*/
size_t			xwrite(int fd, const void *buf, size_t count);

/*
** Checks the return values of fork
** Exits if it fails
*/
pid_t			xfork(void);

int			xgettimeofday(struct timeval *tv, struct timezone *tz);
#endif
