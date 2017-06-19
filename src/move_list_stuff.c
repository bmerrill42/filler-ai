/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_list_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 02:41:30 by bmerrill          #+#    #+#             */
/*   Updated: 2017/06/18 19:06:10 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_movelist	*new_mlist(int x, int y, int score, int me)
{
	t_movelist	*ret;

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
	t_movelist	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		dispose_of_list(t_movelist **list)
{
	t_movelist	*del;

	if (!*list)
		return ;
	del = *list;
	while (*list)
	{
		del = *list;
		*list = (*list)->next;
		free(del);
	}
}
