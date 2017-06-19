/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:17:45 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/07 13:29:03 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char uc = c;
	const unsigned char *su;

	su = s;
	while (0 < n)
	{
		if (*su == uc)
			return ((void *)su);
		++su;
		--n;
	}
	return (0);
}
