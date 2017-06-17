/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:16 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/14 15:31:33 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s1, const char *s2)
{
	const char *sc1;
	const char *sc2;

	sc1 = s1;
	while (*sc1 != '\0')
	{
		sc2 = s2;
		while (*sc1 != *sc2)
		{
			if (*sc2 == '\0')
				return (sc1 - s1);
			++sc2;
		}
		++sc1;
	}
	return (sc1 - s1);
}
