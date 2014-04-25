##
## Makefile for makefile jour01 in /home/corbac_b/work/piscine/cpp/D01M/ex_0
## 
## Made by anthony1 corbacho
## Login   <corbac_b@epitech.net>
## 
## Started on  Mon May  3 10:00:00 2010 anthony1 corbacho
## Last update Mon May  3 11:10:57 2010 anthony1 corbacho
##

NAME	= my_cat
SRCS	= my_cat.cpp
CXX	= g++
CFLAGS	= -W -Wall -Wuninitialized -O
OBJS	= $(SRCS:.cpp=.o)

all	: $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CFLAGS)
clean	:
	rm -f $(OBJS)
	rm -f *~
fclean	: clean
	rm -f $(NAME)

re	: fclean all