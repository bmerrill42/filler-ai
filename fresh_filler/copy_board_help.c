/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_board_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 02:06:48 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 02:06:51 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*copy_new_map_into_old(t_board *board, char *first_line)
{
	int	y;
	int	x;

	y = 0;
	while (y < board->boardheight)
	{
		get_next_line(0, &first_line);
		x = 0;
		while (x + 4 < board->boardwidth + 4)
		{
			if (board->board[y][x] != first_line[x + 4])
				board->board[y][x] = first_line[x + 4];
			x += 1;
		}
		y += 1;
		free(first_line);
	}
	return (first_line);
}
