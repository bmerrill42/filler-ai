/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bounding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 02:40:19 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 02:40:26 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	lowest_y(t_piece *piece)
{
	int	x;
	int	y;

	y = 0;
	while (y < piece->pieceheight)
	{
		x = 0;
		while (x < piece->piecewidth)
		{
			if (piece->piece[y][x] == '*')
				break ;
			x++;
		}
		if (piece->piece[y][x] == '*')
			break ;
		y++;
	}
	return (y);
}

int	lowest_x(t_piece *piece)
{
	int	x;
	int	y;

	x = 0;
	while (x < piece->piecewidth)
	{
		y = 0;
		while (y < piece->pieceheight)
		{
			if (piece->piece[y][x] == '*')
				break ;
			y++;
		}
		if (y < piece->pieceheight)
		{
			if (piece->piece[y][x] == '*')
				break ;
		}
		x++;
	}
	return (x);
}

int	highest_y(t_piece *piece)
{
	int	x;
	int	y;

	y = (piece->pieceheight - 1);
	while (y >= 0)
	{
		x = 0;
		while (x < piece->piecewidth)
		{
			if (piece->piece[y][x] == '*')
				break ;
			x++;
		}
		if (piece->piece[y][x] == '*')
			break ;
		y--;
	}
	return (y);
}

int	highest_x(t_piece *piece)
{
	int	x;
	int	y;

	x = (piece->piecewidth - 1);
	while (x >= 0)
	{
		y = 0;
		while (y < piece->pieceheight)
		{
			if (piece->piece[y][x] == '*')
				break ;
			y++;
		}
		if (y < piece->pieceheight)
		{
			if (piece->piece[y][x] == '*')
				break ;
		}
		x--;
	}
	return (x);
}
