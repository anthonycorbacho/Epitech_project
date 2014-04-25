##
## Makefile for mylib makefile in /home/lornac_a/work/Lib
## 
## Made by mathieu1 lornac
## Login   <lornac_a@epitech.net>
## 
## Started on  Mon Oct 19 09:33:27 2009 mathieu1 lornac
## Last update Wed Mar 31 11:48:30 2010 mathieu1 lornac
##

NAME	= libxsys_`uname -s`.a
HEADER  = lxsys.h

SRCS	= src/xmalloc.c		\
	  src/xclose.c		\
	  src/xdup2.c		\
	  src/xfree.c		\
	  src/xfork.c		\
	  src/xpthread.c	\
	  src/xtime.c		\
	  src/xwrite.c	

OBJS	= $(SRCS:.c=.o)

CC	= cc
RM	= rm -f

INCL	= -I.
CFLAGS	= $(INC) -W -Wall -Wuninitialized -O 

RANLIB	= ranlib
AR	= ar -r


.c.o :	
	$(CC) -c $(CFLAGS) $(INCL) -o $@ $*.c

all:	obj ar ranlib copy clean

obj:	$(OBJS)

ar:	
	$(AR) $(NAME) $(OBJS) 

ranlib:
	$(RANLIB) $(NAME)

copy:
	cp $(NAME) ../all/
	cp $(HEADER) ../all/headers/

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
