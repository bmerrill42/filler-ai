/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_construction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 07:18:47 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/17 03:27:17 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*new_board_matrix(t_board *board, char *first_line)
{
	int i;

	i = 0;
	get_players(board, first_line);
	get_next_line(0, &first_line);
	get_xy_from_str(&board->boardwidth, &board->boardheight, first_line);
	free(first_line);
	get_next_line(0, &first_line);
	free(first_line);
	get_next_line(0, &first_line);
	free(first_line);
	first_line = dup_the_board(board, first_line);
	return (first_line);
}

char	*copy_board_matrix(t_board *board, char *first_line)
{
	while (first_line[0] != '0')
		get_next_line(0, &first_line);
	first_line = copy_new_map_into_old(board, first_line);
	return (first_line);
}

void	new_piece(t_piece *piece, char *line)
{
	int y;

	y = 0;
	get_xy_from_str(&piece->piecewidth, &piece->pieceheight, line);
	piece->piece = (char **)malloc(piece->pieceheight * sizeof(char*));
	while (y < piece->pieceheight)
	{
		get_next_line(0, &line);
		piece->piece[y] = ft_strdup(line);
		y++;
	}
	find_bounding(piece);
}
