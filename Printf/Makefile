NAME	= exe

SRC	= attributs.c			\
	  display_commons.c		\
	  display_int.c			\
	  display_str.c			\
	  display_uint.c		\
	  fromlib1.c			\
	  fromlib2.c			\
	  fromlib3.c			\
	  fromlib4.c			\
	  fromlib5.c			\
	  get_convertion.c		\
	  get_formats.c			\
	  get_len_modif.c		\
	  get_precision_and_field.c	\
	  main.c			\
	  my_printf.c

OBJ	= $(SRC:.c=.o)

CC	= cc
CFLAGS	= $(INC) -W -Wall -Wuninitialized -O -g3
RM	= rm -f
INC	= -I./inc/ -I./inc/lib/headers/x

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) \#*\#

fclean:	clean
	$(RM) $(NAME)

re:	fclean all