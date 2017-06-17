/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:58:36 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/07 13:51:44 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *su1;
	const unsigned char *su2;

	su1 = s1;
	su2 = s2;
	while (0 < n)
	{
		if (*su1 != *su2)
			return (*su1 - *su2);
		++su1;
		++su2;
		--n;
	}
	return (0);
}
