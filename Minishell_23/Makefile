NAME	= mysh

SRC	= built_ins.c		\
	  built_ins2.c		\
	  execution.c		\
	  input.c		\
	  input_bindkey.c	\
	  input_bindkey2.c	\
	  input_utils.c		\
	  input_funcs.c		\
	  input_variables.c	\
	  my_environ.c		\
	  my_environ2.c		\
	  my_getwd.c		\
	  my_ioctl.c		\
	  mysh.c		\
	  mysh_errors.c		\
	  preprocess_input.c	\
	  preprocess_command.c	\
	  preprocess_command2.c	\
	  redirections.c	\
	  redirections_funcs.c	\
	  redirections_funcs2.c	\
	  termcaps.c

HEADDIR	= include
OBJ	= $(SRC:.c=.o)

CC	= cc
CFLAGS	= $(INC) -W -Wall -Wuninitialized -O -g3
RM	= rm -f
LIBS	= -L./inc/lib/ -lstr -lmy -llist -lxsys -lmy_printf_i386-FreeBSD -ltermcap
INC	= -I./inc/ -I./inc/lib/headers/

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	$(RM) $(OBJ)
	$(RM) \#*\#
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all