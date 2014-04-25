NAME	= lib_asm.so

SRCS	=  strstr.S
	# memcpy.S	\
	#   memmove.S	\
	#   memset.S	\
	#   read.S	\
	#   rindex.S	\
	#   strcasecmp.S	\
	#   strchr.S	\
	#   strcmp.S	\
	#   strcspn.S	\
	#   strlen.S	\
	#   strncmp.S	\
	#   strstr.S	\
	#   write.S

OBJS		= $(SRCS:.S=.o)

CC_linux	= cc
CC_FreeBSD	= cc
CC_solaris	= /usr/sfw/bin/gcc
CC		= $(CC_${OSTYPE})

CMD_linux	= -o $(NAME) -shared
CMD_FreeBSD	= -o $(NAME) -shared
CMD_solaris	= -G -o $(NAME)
CMD		= $(CMD_${OSTYPE})

RM		= rm -f

CFLAGS		= -W -Wall -Wuninitialized -O

##
## Rules
##
.c.o :	
	$(CC) -c $(DEFINE) $(CFLAGS) -o $@ $*.c

all:	$(OBJS)
	$(CC) $(CMD) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) \#*\#
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
