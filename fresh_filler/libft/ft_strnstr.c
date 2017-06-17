/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:42:18 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/15 14:52:04 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*strless;
	int		i;
	int		j;
	int		k;

	if (*little == '\0')
		return ((char *)big);
	strless = ft_strsub(big, 0, len);
	i = 0;
	while (strless[i] != '\0')
	{
		j = 0;
		k = i;
		if (strless[i] == little[j])
			while (strless[k] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
				k++;
			}
		i++;
	}
	return (NULL);
}
