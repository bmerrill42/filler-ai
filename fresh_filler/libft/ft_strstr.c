/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:53:42 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/07 13:24:01 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *sc1;
	const char *sc2;

	if (*s2 == '\0')
		return ((char *)s1);
	while ((s1 = ft_strchr(s1, *s2)) != 0)
	{
		sc1 = s1;
		sc2 = s2;
		while (1)
		{
			if (*++sc2 == '\0')
				return ((char *)s1);
			else if (*++sc1 != *sc2)
				break ;
		}
		++s1;
	}
	return (0);
}
