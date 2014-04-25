
NAME	= list
SRCS	= my_list_basics.c			\
	  my_params_in_list.c			\
	  my_list_size.c			\
	  my_rev_list.c				\
	  my_apply_on_list.c			\
	  my_apply_on_eq_in_list.c		\
	  my_find_elm_eq_in_list.c		\
	  my_rm_all_eq_from_list.c		\
	  my_add_list_to_list.c			\
	  my_sort_list.c			\
	  my_put_elem_in_sort_list.c		\
	  my_add_sort_list_to_sort_list.c	\
	  main.c

OBJS	= $(SRCS:.c=.o)

CC	= cc
CCFLAGS = -W -Wall
RM	= rm
LIBS	= -L/nfs/export/work/Lib -lmy
INCL	= -I/nfs/export/work/Lib -I.

all:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS) $(INCLUDES) $(CCFLAGS) 

clean:
	$(RM) $(OBJS)
