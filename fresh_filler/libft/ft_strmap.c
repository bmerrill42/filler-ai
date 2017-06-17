/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:57:37 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/14 14:17:12 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mapstr;
	size_t	index;

	index = 0;
	if (!s || !f)
		return (NULL);
	if (!(mapstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[index] != '\0')
	{
		mapstr[index] = f(s[index]);
		index++;
	}
	return (mapstr);
}
