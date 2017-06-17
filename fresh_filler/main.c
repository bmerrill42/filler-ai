/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:34:27 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/17 03:23:10 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


#include <stdio.h>

void	print_location(t_movelist *largest)
{
	char *x;
	char *y;

	y = ft_itoa(largest->position.y);
	x = ft_itoa(largest->position.x);
	ft_putstr(y);
	ft_putchar(' ');
	ft_putstr(x);
	ft_putchar('\n');
	free(x);
	free(y);
	return ;
}

void	find_the_largest_opchar(t_piece *piece, t_movelist *largest)
{
	t_piece *tmp;

	tmp = piece;
	while (tmp->movelist)
	{
		if (tmp->movelist->opponant_piece_count >
			largest->opponant_piece_count)
		{
			largest->position = tmp->movelist->position;
			largest->opponant_piece_count =
				tmp->movelist->opponant_piece_count;
			largest->my_piece_count = tmp->movelist->my_piece_count;
		}
		tmp->movelist = tmp->movelist->next;
	}
	return ;
}

void	find_the_largest_mechar(t_piece *piece, t_movelist *largest)
{
	t_piece *tmp;

	tmp = piece;
	while (tmp->movelist)
	{
		if (tmp->movelist->my_piece_count <=
			largest->my_piece_count)
		{
			largest->position = tmp->movelist->position;
			largest->opponant_piece_count =
				tmp->movelist->opponant_piece_count;
			largest->my_piece_count = tmp->movelist->my_piece_count;
		}
		tmp->movelist = tmp->movelist->next;
	}
	return ;
}

void	dispose_of_list(t_movelist **list)
{
	if (!*list)
		return ;
	dispose_of_list(&(*list)->next);
	free(*list);
	return ;
}

void	init_largest(t_movelist *largest)
{
	largest->position.x = 0;
	largest->position.y = 0;
	largest->opponant_piece_count = 0;
	largest->my_piece_count = 0;
	largest->next = NULL;
	return ;
}

void set_largest_to_first(t_piece *piece, t_movelist *largest)
{
	if (piece->movelist)
	{
		largest->position = piece->movelist->position;
		largest->opponant_piece_count = piece->movelist->opponant_piece_count;
		largest->my_piece_count = piece->movelist->my_piece_count;
		largest->next = NULL;
	}
	return ;
}

void	pick_a_spot(t_piece *piece)
{
	t_movelist	largest;
	t_movelist *head;

	head = NULL;
	if (piece->movelist)
		head = piece->movelist;
	init_largest(&largest);
	set_largest_to_first(piece, &largest);
	find_the_largest_opchar(piece, &largest);
	if (largest.opponant_piece_count == 0)
	{
		if (piece->movelist)
			head = piece->movelist;
		piece->movelist = head;
		set_largest_to_first(piece, &largest);
		find_the_largest_mechar(piece, &largest);
	}
	largest.next = NULL;
	print_location(&largest);
	dispose_of_list(&piece->movelist);
	return ;
}

void	build_move_list(t_board *board, t_piece *piece)
{
	board->current_position.x = 0;
	board->current_position.y = 0;
	while (board->current_position.y < board->boardheight)
	{
		board->current_position.x = 0;
		while (board->current_position.x < board->boardwidth)
		{
			if (scan(board, piece, board->current_position.x,
					 board->current_position.y))
			{
				if (is_legal(board, piece, board->current_position.x,
							 board->current_position.y))
				{
					score_and_add_position(board, piece,
										   board->current_position.x,
										   board->current_position.y);
				}
			}
			board->current_position.x++;
		}
		board->current_position.y++;
	}
	return ;
}

void	matrix_free(char **matrix)
{
	int y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
}

void	populate_structs(t_board *board, t_piece *piece, char *first_line)
{
	char *free_me;

	free_me = first_line;
	if (board->board == NULL)
	{
		first_line = new_board_matrix(board, first_line);
//		free(free_me);
	}
	else
	{
		first_line = copy_board_matrix(board, first_line);
		free(free_me);
	}
//	if (piece->piece != NULL)
//		matrix_free(piece->piece);
	new_piece(piece, first_line);
	return ;
}

int		main(void)
{
	char	*line;
	t_board	board;
	t_piece	piece;

	ft_bzero(&board, sizeof(t_board));
	ft_bzero(&piece, sizeof(t_piece));
	while (get_next_line(0, &line))
	{
		populate_structs(&board, &piece, line);
		build_move_list(&board, &piece);
		pick_a_spot(&piece);
//		free(&line);
	}
	free(line);
	matrix_free(board.board);
	matrix_free(piece.piece);
//	sleep(30);
	return (0);
}
