##
## Makefile for Makefile in /home/corbac_b/My Dropbox/epitech/C/my_script
## 
## Made by anthony1 corbacho
## Login   <corbac_b@epitech.net>
## 
## Started on  Mon Feb  8 23:30:46 2010 anthony1 corbacho
## Last update Fri Feb 19 18:31:07 2010 anthony1 corbacho
##


NAME		= my_script
SRCS		= ./lib/my_strdup.c		\
		  ./lib/my_strcpy.c		\
		  ./lib/my_putchar.c		\
		  ./lib/my_putstr.c		\
		  ./lib/my_strlen.c		\
		  ./lib/my_strcmp.c		\
		  ./src/aux_func.c		\
		  ./src/func_control.c		\
		  ./src/func_control_2.c	\
		  ./src/func_error.c		\
		  ./src/func_file.c		\
		  ./src/my_script.c		\
		  ./src/func_inc_terminal.c	\
		  ./src/execute_command.c	\
		  ./xfunc/xfunction.c
OBJS		= $(SRCS:.c=.o) $(${HOSTTYPE}:.c=.o)
FreeBSD		= ./FreeBSD/my_forkpty.c	\
		  ./FreeBSD/my_login_tty.c	\
		  ./FreeBSD/my_opentty.c	\
		  ./FreeBSD/termcaps.c
i486-linux	= ./Linux/my_forkpty.c		\
		  ./Linux/my_login_tty.c	\
		  ./Linux/my_opentty.c		\
		  ./Linux/termcaps.c
CC		= cc -g3
CFLAGS		= -W -Wall -pedantic -I./h
RM		= rm -f

all		:$(NAME)

.c.o		:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)		:$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean		:
		$(RM) $(OBJS)
		$(RM) *~

fclean		:clean
		rm -f $(NAME)

re		:fclean all