/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_move_list_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:12:54 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/17 01:57:51 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_player_board(char check, char player)
{
	if (check == player || check == player + 32)
		return (1);
	else
		return (0);
}

int	collision_check(t_board *board, t_piece *piece, int x, int y)
{
	int			collision;
	t_xypair	piece_place;
	t_xypair	og_xy;

	og_xy.x = x;
	og_xy.y = y;
	piece_place.x = piece->bound_nw.x;
	piece_place.y = piece->bound_nw.y;
	collision = 0;
	if (y < board->boardheight && x < board->boardwidth)
		collision = collision_help(board, piece, &piece_place, &og_xy);
	else
		return (1);
	if (x + (piece->bound_se.x - piece_place.x) >= board->boardwidth ||
		y + (piece->bound_se.y - piece_place.y) >= board->boardheight)
		return (1);
	return (collision);
}

int	overlap_check(t_board *board, t_piece *piece, int x, int y)
{
	int			overlap;
	t_xypair	piece_place;
	t_xypair	og_xy;

	og_xy.x = x;
	og_xy.y = y;
	piece_place.x = piece->bound_nw.x;
	piece_place.y = piece->bound_nw.y;
	overlap = 0;
	if (y < board->boardheight && x < board->boardwidth)
		overlap = overlap_help(board, piece, &piece_place, &og_xy);
	else
		return (0);
	if (x + (piece->bound_se.x - piece_place.x) >= board->boardwidth)
		return (0);
	return (overlap);
}

int	is_legal(t_board *board, t_piece *piece, int x, int y)
{
	if (overlap_check(board, piece, x, y) == 1 &&
		!collision_check(board, piece, x, y))
		return (1);
	else
		return (0);
}

int	scan(t_board *board, t_piece *piece, int x, int y)
{
	t_xypair	c;

	set_corner(piece, &c);
	if (y < board->boardheight && x < board->boardwidth)
		while (c.y <= piece->bound_se.y && y < board->boardheight)
		{
			if (y + (piece->bound_se.y) >= board->boardheight)
				return (0);
			c.x = piece->bound_nw.x;
			if (x + (piece->bound_se.x - c.x) < board->boardwidth)
				while (c.x <= piece->bound_se.x && x < board->boardwidth)
				{
					if (check_player_board(board->board[y][x], board->playerme))
						return (1);
					double_inc(&x, &c.x);
				}
			else
				return (0);
			x -= (piece->bound_se.x - piece->bound_nw.x) + 1;
			double_inc(&y, &c.y);
		}
	return (0);
}
