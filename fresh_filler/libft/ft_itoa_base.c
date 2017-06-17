/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:21:43 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/01 16:34:15 by bmerrill         ###   ########.fr       */
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

char		*ft_itoa_base(uintmax_t value, int base)
{
	int		size;
	char	*ret;
	char	*conv;

	conv = "0123456789ABCDEF";
	size = get_conv_size(value, base);
	ret = ft_strnew(size);
	while (size > 0)
	{
		ret[--size] = conv[value % base];
		value /= base;
	}
	return (ret);
}
