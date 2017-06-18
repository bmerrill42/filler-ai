/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_piece_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 02:05:23 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 02:05:44 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_bounding(t_piece *piece)
{
	piece->bound_nw.y = lowest_y(piece);
	piece->bound_nw.x = lowest_x(piece);
	piece->bound_se.y = highest_y(piece);
	piece->bound_se.x = highest_x(piece);
}
