/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:44:10 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/01 16:34:35 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_conv_size(uintmax_t value, int base)
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

char		*ft_itoa_u(uintmax_t n)
{
	int		size;
	char	*ret;
	char	*conv;

	conv = "0123456789";
	size = get_conv_size(n, 10);
	ret = ft_strnew(size);
	while (size > 0)
	{
		ret[--size] = conv[n % 10];
		n /= 10;
	}
	return (ret);
}
