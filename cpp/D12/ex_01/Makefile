##
## Makefile for  in /home/athel/Documents/CPP/D01M/ex_0
## 
## Made by olivier1 cazade
## Login   <cazade_a@epitech.net>
## 
## Started on  Mon May  3 10:14:08 2010 olivier1 cazade
##

NAME		= autorun

SRC		= Knight.cpp	\
		  Stats.cpp		\
		  main.cpp

OBJ		= $(SRC:.cpp=.o)
CPP		= g++
CXXFLAGS	= -W -Wall -O -Wuninitialized ##-pedantic -ansi ##-Werror
LIB		= 
INC		= -I.
RM		= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CPP) -o $@ $(OBJ) $(CXXFLAGS) $(LIB) $(INC)

.cpp.o	:
	$(CPP) -o $@ -c $< $(CXXFLAGS) $(INC)

clean	:
	$(RM) $(OBJ)
	$(RM) */*~
	$(RM) *~

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
