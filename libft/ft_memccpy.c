/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:24:24 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/07 13:26:51 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tp;
	const unsigned char	*fp;
	unsigned char		uc;

	if (n)
	{
		tp = dst;
		fp = src;
		uc = c;
		while (n != 0)
		{
			if ((*tp++ = *fp++) == uc)
				return (tp);
			--n;
		}
	}
	return (0);
}
