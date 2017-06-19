/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:38:31 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 14:41:37 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int side)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + ft_strlen(s1)), s2);
	if (side == FREE_LEFT)
		free((void**)s1);
	if (side == FREE_RIGHT)
		free((void**)s2);
	if (side == FREE_BOTH)
	{
		free((void**)s1);
		free((void**)s2);
	}
	return (join);
}
