/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:18:43 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/06 12:47:28 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_conv_size(intmax_t value, int base)
{
	int	i;

	i = 0;
	if (value == 0)
	{
		i++;
		return (i);
	}
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa(intmax_t n)
{
	int		size;
	char	*ret;
	int		neg;
	char	*conv;

	conv = "0123456789";
	neg = 0;
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	size = get_conv_size(n, 10);
	ret = ft_strnew(size + neg);
	size += (neg > 0) ? 1 : 0;
	while (size > 0)
	{
		ret[--size] = conv[n % 10];
		n /= 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
