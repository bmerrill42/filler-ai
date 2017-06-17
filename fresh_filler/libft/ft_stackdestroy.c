/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdestroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:46:01 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/17 12:42:29 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackdestroy(t_stack *stack)
{
	free(stack->contents);
	stack->contents = NULL;
	stack->max_size = 0;
	stack->top = -1;
}
