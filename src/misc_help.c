/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:15:10 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/17 01:18:29 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		collision_help(t_board *b, t_piece *p,
					t_xypair *p_xy, t_xypair *o_xy)
{
	int collision;

	collision = 0;
	while (p_xy->y <= p->bound_se.y && o_xy->y < b->boardheight)
	{
		if (o_xy->y + (p->bound_se.y - p_xy->y) > b->boardheight - 1)
			return (0);
		p_xy->x = p->bound_nw.x;
		if (o_xy->x + (p->bound_se.x - p_xy->x) < b->boardwidth)
			while (p_xy->x <= p->bound_se.x && o_xy->x < b->boardwidth)
			{
				if (p->piece[p_xy->y][p_xy->x] == '*' &&
					(check_player_board(b->board[o_xy->y][o_xy->x],
										b->playerop)))
					collision++;
				o_xy->x++;
				p_xy->x++;
			}
		else
			break ;
		o_xy->x -= (p->bound_se.x - p->bound_nw.x) + 1;
		o_xy->y++;
		p_xy->y++;
	}
	return (collision);
}

int		overlap_help(t_board *b, t_piece *p,
					t_xypair *p_xy, t_xypair *o_xy)
{
	int overlap;

	overlap = 0;
	while (p_xy->y <= p->bound_se.y && o_xy->y < b->boardheight)
	{
		if (o_xy->y + (p->bound_se.y - p_xy->y) > b->boardheight - 1)
			return (0);
		p_xy->x = p->bound_nw.x;
		if (o_xy->x + (p->bound_se.x - p_xy->x) < b->boardwidth)
			while (p_xy->x <= p->bound_se.x && o_xy->x < b->boardwidth)
			{
				if (p->piece[p_xy->y][p_xy->x] == '*' &&
					(check_player_board(b->board[o_xy->y][o_xy->x],
										b->playerme)))
					overlap++;
				o_xy->x++;
				p_xy->x++;
			}
		else
			break ;
		o_xy->x -= (p->bound_se.x - p->bound_nw.x) + 1;
		o_xy->y++;
		p_xy->y++;
	}
	return (overlap);
}

void	double_inc(int *a, int *b)
{
	(*a)++;
	(*b)++;
}

void	set_corner(t_piece *piece, t_xypair *corner)
{
	corner->x = piece->bound_nw.x;
	corner->y = piece->bound_nw.y;
}
