/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:22:26 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/14 14:25:22 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapstr;
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return (NULL);
	if (!(mapstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[index] != '\0')
	{
		mapstr[index] = f(index, s[index]);
		index++;
	}
	return (mapstr);
}
