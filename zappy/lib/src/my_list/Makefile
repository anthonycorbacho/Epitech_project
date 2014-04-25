##
## Makefile for libmy in /home/coppel_a/work/lib/my
## 
## Made by damien1 coppel
## Login   <coppel_a@epitech.net>
## 
## Started on  Mon Oct 19 11:11:49 2009 damien1 coppel
## Last update Thu Nov  5 14:30:38 2009 damien1 coppel
##

NAME	=	libmy_list.a
SRCS	=	my_add_list_to_list.c			\
		my_add_sort_list_to_sort_list.c		\
		my_apply_on_eq_in_list.c		\
		my_apply_on_list.c			\
		my_find_elm_eq_in_list.c		\
		my_find_node_eq_in_list.c		\
		my_list_size.c				\
		my_params_in_list.c			\
		my_put_elem_in_sort_list.c		\
		my_rev_list.c				\
		my_rm_all_eq_from_list.c		\
		my_sort_list.c				\
		my_free_all_list.c			\
		my_put_elem_in_list.c

OBJS	=	$(SRCS:.c=.o)
CC	=	cc
RM	=	rm
INCL	=	-I ../../include/
LIB     =	-L ../ -lmy
CFLAGS	=	-I. -W -Wall

all	: obj

obj	: $(OBJS)
	  ar -r $(NAME) $(OBJS)
	  ranlib $(NAME)
	  cp $(NAME) ../
	  cp my_list.h ../../include/

clean	: 
	  $(RM) -f $(OBJS)
