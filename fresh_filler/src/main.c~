/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:34:27 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 02:28:02 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	pick_a_spot(t_piece *piece)
{
	t_movelist	largest;
	t_movelist	*head;

	head = NULL;
	if (piece->movelist)
		head = piece->movelist;
	init_largest(&largest);
	set_largest_to_first(piece, &largest);
	find_the_largest_opchar(piece, &largest);
	if (largest.opponant_piece_count == 0)
	{
		if (piece->movelist && head)
			head = piece->movelist;
		piece->movelist = head;
		set_largest_to_first(piece, &largest);
		find_the_largest_mechar(piece, &largest);
	}
	largest.next = NULL;
	print_location(&largest);
	if (piece->movelist && head)
		head = piece->movelist;
	dispose_of_list(&head);
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

void	matrix_free(char **matrix, int max)
{
	int y;

	y = 0;
	while (y < max)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	matrix = NULL;
}

void	populate_structs(t_board *board, t_piece *piece, char *first_line)
{
	if (board->board == NULL)
		first_line = new_board_matrix(board, first_line);
	else
		first_line = copy_board_matrix(board, first_line);
	if (piece->piece != NULL)
		matrix_free(piece->piece, piece->pieceheight);
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
	}
	free(line);
	get_next_line(-42, &line);
	matrix_free(board.board, board.boardheight);
	matrix_free(piece.piece, piece.pieceheight);
	return (0);
}
