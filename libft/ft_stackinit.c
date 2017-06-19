/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:49:29 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/17 12:42:50 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackinit(t_stack *stack, int maxsize)
{
	t_stackelem *newstuff;

	if (!(newstuff = (t_stackelem *)malloc(sizeof(t_stackelem) * maxsize)))
	{
		ft_putendl_fd("not enough memory", 2);
		exit(1);
	}
	stack->contents = newstuff;
	stack->max_size = maxsize;
	stack->top = -1;
}
