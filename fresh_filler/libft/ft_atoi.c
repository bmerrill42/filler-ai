/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:49:16 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/15 15:41:10 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char a)
{
	if (a == '\t' || a == '\n' || a == '\v' ||
		a == '\f' || a == '\r' || a == ' ')
		return (1);
	else
		return (0);
}

int				ft_atoi(char *str)
{
	unsigned int	number;
	int				negative;

	negative = 0;
	number = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	if (negative < 0)
		return (number *= negative);
	return (number);
}
