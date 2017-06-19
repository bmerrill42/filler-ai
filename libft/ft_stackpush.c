/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:02:44 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/17 12:43:37 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack *stack, t_stackelem element)
{
	if (ft_stackisfull(stack))
	{
		ft_putstr_fd("stack is full", 2);
		exit(1);
	}
	stack->contents[++stack->top] = element;
}
