##
## Makefile for my_script in /home/lornac_a/work/My Dropbox/Epitech/
## 
## Made by mathieu1 lornac
## Login   <lornac_a@epitech.net>
## 
## Started on  Sat Feb 13 14:35:32 2010 mathieu1 lornac
## Last update Sun Apr 25 17:40:40 2010 mathieu1 lornac

##
## COMMON SOURCES
##
CM_DIR	= src_common
CM_SRCS	= $(CM_DIR)/definitions.c		\
	  $(CM_DIR)/ip_connection.c		\
	  $(CM_DIR)/ip_protocol.c		\
	  $(CM_DIR)/map.c			\
	  $(CM_DIR)/map_initialize.c		\
	  $(CM_DIR)/position.c			\
	  $(CM_DIR)/args/args.c			\
	  $(CM_DIR)/args/port.c			\
	  $(CM_DIR)/args/find_time.c		\
	  $(CM_DIR)/args/find_team_name.c	\
	  $(CM_DIR)/args/find_guest.c		\
	  $(CM_DIR)/args/find_map.c		\
	  $(CM_DIR)/get_next_line.c		\
	  $(CM_DIR)/str_utils.c			\
	  $(CM_DIR)/str_utils_2.c

##
## GRAPHIC
##
GC_NAME = graphic

GC_DIR  = src_graphic
GC_SRCS = $(GC_DIR)/thread_listen.c	\
	  $(GC_DIR)/thread_actions.c	\
	  $(GC_DIR)/launch_sdl.c	\
	  $(GC_DIR)/sdl_function.c	\
	  $(GC_DIR)/sdl_function_next.c	\
	  $(GC_DIR)/sdl_init_map.c	\
	  $(GC_DIR)/sdl_movement.c	\
	  $(GC_DIR)/sdl_movement_radar.c	\
	  $(GC_DIR)/sdl_print_items.c	\
	  $(GC_DIR)/user.c		\
	  $(GC_DIR)/thread_pin.c	\
	  $(GC_DIR)/user_action.c	\
	  $(GC_DIR)/sdl_put_updown.c	\
	  $(GC_DIR)/egg.c		\
	  $(GC_DIR)/thread_pnw.c	\
	  $(GC_DIR)/sdl_egg.c		\
	  $(GC_DIR)/put_menu_items.c	\
	  $(GC_DIR)/put_menu_minimap.c	\
	  $(GC_DIR)/put_menu_monsters.c	\
	  $(GC_DIR)/sdl_content_case.c	\
	  $(GC_DIR)/xsdl.c		\
	  $(GC_DIR)/sdl_user.c		\
	  $(GC_DIR)/sdl_user_actions.c	\
	  $(GC_DIR)/sdl_event_management.c \
	  $(GC_DIR)/sdl_init_rect.c	\
	  $(GC_DIR)/put_menu.c		\
	  $(GC_DIR)/get_next_line_socket.c	\
	  $(GC_DIR)/main.c		\
	  $(GC_DIR)/my_rand.c		\
	  $(GC_DIR)/sdl_monsters_case.c \
	  $(GC_DIR)/sdl_update_scroll_users.c \
	  $(GC_DIR)/sdl_event_time.c	\
	  $(GC_DIR)/sdl_print_invent.c	\
	  $(GC_DIR)/sdl_put_monster_minimap.c

GC_OBJ  = $(GC_SRCS:.c=.o) $(CM_SRCS:.c=.o)

##
## Server SOURCES
##
SR_NAME	= serveur

SR_DIR	= src_server
SR_SRCS	= $(SR_DIR)/main.c			\
	  $(SR_DIR)/cell_listing.c		\
	  $(SR_DIR)/client_management.c		\
	  $(SR_DIR)/commands_srv.c		\
	  $(SR_DIR)/egg_management.c		\
	  $(SR_DIR)/egg_management2.c		\
	  $(SR_DIR)/life_management.c		\
	  $(SR_DIR)/process_clients.c		\
	  $(SR_DIR)/request.c			\
	  $(SR_DIR)/request_receive.c		\
	  $(SR_DIR)/send_to.c			\
	  $(SR_DIR)/team_management.c		\
	  $(SR_DIR)/team_management_2.c		\
	  $(SR_DIR)/time_management.c		\
	  $(SR_DIR)/time_manipulation.c		\
	  $(SR_DIR)/vision.c			\
	  $(SR_DIR)/welcome.c			\
	  $(SR_DIR)/win_game.c			\
	  $(SR_DIR)/action/send_graph.c		\
	  $(SR_DIR)/action/avance.c		\
	  $(SR_DIR)/action/broadcast.c		\
	  $(SR_DIR)/action/connect_nbr.c	\
	  $(SR_DIR)/action/droite.c		\
	  $(SR_DIR)/action/expulse.c		\
	  $(SR_DIR)/action/forky.c		\
	  $(SR_DIR)/action/gauche.c		\
	  $(SR_DIR)/action/incantation.c	\
	  $(SR_DIR)/action/inventaire.c		\
	  $(SR_DIR)/action/pose.c		\
	  $(SR_DIR)/action/prend.c		\
	  $(SR_DIR)/action/voir.c		\
	  $(SR_DIR)/graphic/egg_gr.c		\
	  $(SR_DIR)/graphic/forky_gr.c		\
	  $(SR_DIR)/graphic/map_gr.c		\
	  $(SR_DIR)/graphic/map_gr_2.c		\
	  $(SR_DIR)/graphic/player1_gr.c	\
	  $(SR_DIR)/graphic/player2_gr.c	\
	  $(SR_DIR)/graphic/player3_gr.c	\
	  $(SR_DIR)/graphic/player4_gr.c	\
	  $(SR_DIR)/graphic/team_gr.c		\
	  $(SR_DIR)/graphic/time_gr.c		\
	  $(SR_DIR)/graphic/cmd_rcv_gr.c	\
	  $(SR_DIR)/graphic/cmd_rcv2_gr.c

SR_OBJ	= $(SR_SRCS:.c=.o) $(CM_SRCS:.c=.o)

##
## CLIENT SOURCES
##
CT_NAME	= client
CT_DIR	= src_client
CT_SRCS	= $(CT_DIR)/main.c			\
	  $(CT_DIR)/player_management.c		\
	  $(CT_DIR)/replicate.c			\
	  $(CT_DIR)/check_case.c		\
	  $(CT_DIR)/get_next_line_socket.c	\
	  $(CT_DIR)/food.c			\
	  $(CT_DIR)/jewel.c			\
	  $(CT_DIR)/client_incantation.c	\
	  $(CT_DIR)/client_movement.c		\
	  $(CT_DIR)/case_is_empty.c		\
	  $(CT_DIR)/get_params.c		\
	  $(CT_DIR)/chain_receive.c		\
	  $(CT_DIR)/get_XY_from_cell.c		\
	  $(CT_DIR)/player_init.c		\
	  $(CT_DIR)/broadcast_move.c		\
	  $(CT_DIR)/broadcast.c			\
	  $(CT_DIR)/gnl_parsing.c		\
	  $(CT_DIR)/check_cells_around.c	\
	  $(CT_DIR)/get_players_case.c

CT_OBJ	= $(CT_SRCS:.c=.o) $(CM_SRCS:.c=.o)

##
## TELNET SOURCES
##
TL_NAME	= telnet
TL_DIR	= src_telnet
TL_SRCS	= $(TL_DIR)/main.c			\
	  $(TL_DIR)/get_next_line.c
TL_OBJ	= $(TL_SRCS:.c=.o) $(CM_SRCS:.c=.o)

##
## Compilators path
##
CC_linux	= cc
CC_FreeBSD	= cc
CC_solaris	= /usr/sfw/bin/gcc
CC		= $(CC_${OSTYPE})

INCL		= -I./src_server/inc		\
		  -I./src_common/inc		\
		  -I./src_client/inc		\
		  -I./src_graphic/inc		\
		  -I./lib/inc

LIB		= -L./lib/			\
		  -lxsys_`uname -s`		\
		  -lstr_`uname -s`		\
		  -lmy_printf_`uname -s`	\
		  -lmy_`uname -s`		\
		  -llist_`uname -s`		\
		  -lpthread

LIBGRAPHIC	= $(LIB)			\
		  -lSDL_image			\
		  -lSDL_ttf			\
		  -lSDL				\
		  -lfmod-3.75

CFLAGS		= -W -Wall -O -Wuninitialized

RM		= rm -f

##
## RULES
##
all:	client server

.c.o :
	$(CC) -c $(CFLAGS) $(INCL) -o $@ $*.c

server:	$(SR_OBJ)
	$(CC) -o $(SR_NAME) $(SR_OBJ) $(INCL) $(LIB)

client:	$(CT_OBJ)
	$(CC) -o $(CT_NAME) $(CT_OBJ) $(INCL) $(LIB)

graphic: $(GC_OBJ)
	 $(CC) -o $(GC_NAME) $(GC_OBJ) $(INCL) $(LIBGRAPHIC)

telnet:	$(TL_OBJ)
	$(CC) -o $(TL_NAME) $(TL_OBJ) $(INCL) $(LIB)

clean:
	$(RM) $(SR_OBJ) $(CT_OBJ) $(GC_OBJ) $(TL_OBJ)
	$(RM) \#*\#
	$(RM) *~
	$(RM) $(SR_DIR)/*~
	$(RM) $(SR_DIR)/\#*\#
	$(RM) $(SR_DIR)/inc/*~
	$(RM) $(SR_DIR)/inc/\#*\#
	$(RM) $(SR_DIR)/action/*~
	$(RM) $(SR_DIR)/action/\#*\#
	$(RM) $(SR_DIR)/graphic/*~
	$(RM) $(SR_DIR)/graphic/\#*\#
	$(RM) $(CT_DIR)/*~
	$(RM) $(CM_DIR)/*~
	$(RM) $(GC_DIR)/*~
	$(RM) $(TL_DIR)/*~
	$(RM) $(CT_DIR)/inc/*~
	$(RM) $(CM_DIR)/inc/*~
	$(RM) $(GC_DIR)/inc/*~
	$(RM) $(CT_DIR)/\#*\#
	$(RM) $(CM_DIR)/\#*\#
	$(RM) $(GC_DIR)/\#*\#
	$(RM) $(TL_DIR)/\#*\#
	$(RM) $(CT_DIR)/inc/\#*\#
	$(RM) $(GC_DIR)/inc/\#*\#
	$(RM) $(CM_DIR)/inc/\#*\#

fclean:	clean
	$(RM) $(SR_NAME) $(CT_NAME) $(GC_NAME) $(TL_NAME)

re:	fclean all
