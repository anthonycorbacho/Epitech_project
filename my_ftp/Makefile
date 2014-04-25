##
## Makefile for ftp in /home/anthony/Projet/my_ftp
## 
## Made by anthony1 corbacho
## Login   <corbac_b@epitech.net>
## 
## Started on  Mon Feb 22 17:41:13 2010 anthony1 corbacho
## Last update Fri Mar 12 11:25:46 2010 anthony1 corbacho
##

NAME_SRV	= server
NAME_CLT	= client

SRC_ALL		=./xlib/xfree.c		\
		 ./xlib/xmalloc.c	\
		 ./xlib/xfork.c		\
		 ./xlib/xwait.c		\
		 ./xlib/xwrite.c	\
		 ./src/func_error.c	\
		 ./src/my_recv.c	\
		 ./src/my_send.c	\
		 ./src/read_write_sock.c	\
		 ./src/aux_func.c

SRC_CLT		=./src_client/main.c		\
		 ./src_client/get_file_c.c	\
		 ./src_client/my_memset.c	\
		 ./src_client/put_l_function.c	\
		 ./src_client/exec_cmd.c	\
		 ./src_client/put_function.c	\
		 ./src_client/put_file_c.c	\
		 ./src_client/fund_host.c	\
		 ./src_client/welcome_bye.c	\
		 ./src_client/initialize_connexion.c

SRC_SRV		=./src_server/main.c		\
		 ./src/my_strcat_.c		\
		 ./src_server/get_file.c	\
		 ./src_server/extract_cmd.c	\
		 ./src_server/my_memset.c	\
		 ./src_server/option_cmd.c	\
		 ./src_server/put_file.c	\
		 ./src_server/welcome_bye.c	\
		 ./src_server/exec_cmd.c	\
		 ./src_server/start_server.c

CC		= gcc
OBJS_CLT	= $(SRC_ALL:.c=.o) $(SRC_CLT:.c=.o)
OBJS_SRV	= $(SRC_ALL:.c=.o) $(SRC_SRV:.c=.o)
LIB		= -L./lib -lmy
CFLAGS		= -W -Wall -ansi -pedantic -I./header
RM		= rm -f

all		: $(NAME_SRV) $(NAME_CLT)

.c.o		:
		$(CC) $(CFLAGS) -c $*.c  -o $@

$(NAME_SRV)	: $(OBJS_SRV)
		$(CC) -o $(NAME_SRV) $(OBJS_SRV) $(LIB)

$(NAME_CLT)	: $(OBJS_CLT)
		$(CC) -o $(NAME_CLT) $(OBJS_CLT) $(LIB)

clean		:
		$(RM) $(OBJS_SRV)
		$(RM) $(OBJS_CLT)
		$(RM) *~
		$(RM) ./src_server/*~
		$(RM) ./src_client/*~
		$(RM) ./src/*~

fclean		: clean
		$(RM) $(NAME_CLT)
		$(RM) $(NAME_SRV)

re		: fclean all