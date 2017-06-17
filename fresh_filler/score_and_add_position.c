/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_and_add_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:34:37 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/17 01:57:47 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_movelist	*new_mlist(int x, int y, int score, int me)
{
	t_movelist *ret;

	ret = (t_movelist *)malloc(sizeof(t_movelist));
	ret->position.x = x;
	ret->position.y = y;
	ret->my_piece_count = me;
	ret->opponant_piece_count = score;
	ret->next = NULL;
	return (ret);
}

void		add_mlist(t_movelist **list, t_movelist *new)
{
	t_movelist *tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		expand_corners(t_piece *piece, t_xypair *nw,
							t_xypair *se, int offset)
{
	nw->x = piece->bound_nw.x - offset;
	nw->y = piece->bound_nw.y - offset;
	se->x = piece->bound_se.x + offset;
	se->y = piece->bound_se.y + offset;
}

void		adjust_search_within_bounds(t_xypair *pos, t_xypair *se,
										t_board *board)
{
	while (board->current_position.x + pos->x < 0)
		pos->x++;
	while (board->current_position.y + pos->y < 0)
		pos->y++;
	while (board->current_position.x + se->x-- > board->boardwidth - 1)
		;
	while (board->current_position.y + se->y-- > board->boardheight - 1)
		;
}

void		get_score_counts(t_board *b, t_piece *p, t_xypair *pos)
{
	while (pos->y < p->searchboundse.y)
	{
		pos->x = p->searchboundnw.x;
		while (pos->x <= p->searchboundse.x)
		{
			if (b->board[b->current_position.y + pos->y]
						[b->current_position.x + pos->x] == b->playerop)
				p->op_count += 1;
			if (b->board[b->current_position.y + pos->y]
						[b->current_position.x + pos->x] == b->playerme)
				p->me_count += 1;
			pos->x++;
		}
		pos->y++;
	}
}

void		score_and_add_position(t_board *board, t_piece *piece, int x, int y)
{
	t_xypair position;

	piece->me_count = 0;
	piece->op_count = 0;
	expand_corners(piece, &piece->searchboundnw, &piece->searchboundse, 3);
	position.x = piece->searchboundnw.x;
	position.y = piece->searchboundnw.y;
	adjust_search_within_bounds(&position, &piece->searchboundse, board);
	get_score_counts(board, piece, &position);
	if (!piece->movelist)
		piece->movelist = new_mlist(x - piece->bound_nw.x, y - piece->bound_nw.y
									,piece->op_count, piece->me_count);
	else
		add_mlist(&(piece->movelist),
				  new_mlist(x - piece->bound_nw.x, y - piece->bound_nw.y,
					piece->op_count, piece->me_count));
}
