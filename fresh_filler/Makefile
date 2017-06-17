#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 18:31:30 by bmerrill          #+#    #+#              #
#    Updated: 2017/06/15 18:21:17 by bmerrill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
FLAGS=-Wall -Werror -Wextra -lncurses
OBJDIR=obj/
CFILES= main.c build_move_list_help.c copy_board_help.c find_bounding.c matrix_construction.c new_board_help.c new_piece_help.c score_and_add_position.c misc_help.c
OFILES=$(CFILES:.c=.o)
NAME=filler
INCLUDE=libft/
all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(FLAGS) libft/libft.a -g $(CFILES) -o $(NAME)
#	cp -f $(NAME) fillerdir
$(OFILES): $(CFILES)
	$(CC) $(FLAGS) -c $(CFILES)
