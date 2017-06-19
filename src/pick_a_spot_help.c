/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_a_spot_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 02:29:08 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 21:03:36 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	while (piece->movelist)
	{
		if (piece->movelist->opponant_piece_count >
			largest->opponant_piece_count)
		{
			largest->position = piece->movelist->position;
			largest->opponant_piece_count =
				piece->movelist->opponant_piece_count;
			largest->my_piece_count = piece->movelist->my_piece_count;
		}
		piece->movelist = piece->movelist->next;
	}
	return ;
}

void	find_the_largest_mechar(t_piece *piece, t_movelist *largest)
{
	while (piece->movelist)
	{
		if (piece->movelist->my_piece_count <
			largest->my_piece_count)
		{
			largest->position = piece->movelist->position;
			largest->opponant_piece_count =
				piece->movelist->opponant_piece_count;
			largest->my_piece_count = piece->movelist->my_piece_count;
		}
		piece->movelist = piece->movelist->next;
	}
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

void	set_largest_to_first(t_piece *piece, t_movelist *largest)
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
