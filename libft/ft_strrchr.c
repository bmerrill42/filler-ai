/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:24:08 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/15 13:11:42 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*sc;

	ch = c;
	sc = NULL;
	while (*s != '\0')
	{
		if (*s == ch)
			sc = s;
		s++;
	}
	if (*s == '\0' && c == '\0')
		sc = s;
	return ((char *)sc);
}
