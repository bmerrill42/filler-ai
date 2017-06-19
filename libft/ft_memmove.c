/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:38:45 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/05 19:53:17 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_pointer;
	const char	*src_pointer;

	dst_pointer = dst;
	src_pointer = src;
	if (src_pointer < dst_pointer && dst_pointer < src_pointer + len)
	{
		dst_pointer += len;
		src_pointer += len;
		while (0 < len)
		{
			*--dst_pointer = *--src_pointer;
			--len;
		}
	}
	else
	{
		while (0 < len)
		{
			*dst_pointer++ = *src_pointer++;
			--len;
		}
	}
	return (dst);
}
