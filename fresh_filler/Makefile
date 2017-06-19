#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 18:31:30 by bmerrill          #+#    #+#              #
#    Updated: 2017/06/18 21:06:58 by bmerrill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
OBJDIR=./obj/
FLAGS=-Wall -Werror -Wextra
CFILES= main.c \
		build_move_list_help.c \
		copy_board_help.c \
		find_bounding.c \
		matrix_construction.c \
		new_board_help.c \
		new_piece_help.c \
		score_and_add_position.c \
		misc_help.c \
		move_list_stuff.c \
		pick_a_spot_help.c
OFILES=$(addprefix $(OBJDIR),$(CFILES:.c=.o))
NAME=players/filler
LIBFT=./libft/
LLFT=libft/libft.a
INCLUDE=./includes/
VIS=graphics.butts
VISFILES=visualizer.c
VISLIB=-lncurses
VPATH=src/:obj/

all: $(NAME) $(VIS)

$(VIS): $(VISFILES)
	$(CC) $(FLAGS) $(VISLIB) -I$(INCLUDE) -L$(LIBFT) $(LLFT) $< -o $(VIS)

$(NAME): $(LLFT) $(OFILES)
	$(CC) $(FLAGS) -I$(INCLUDE) -L$(LIBFT) $(LLFT) $(OFILES) -o $(NAME)



obj/%.o: src/%.c
	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

$(LLFT):
	make -C libft/

clean:
	rm -f $(OFILES)
	make -C libft/ clean

fclean: clean
	rm -f players/$(NAME) $(VIS)
	make -C libft/ fclean

re: fclean all

.phony: all clean fclean re
