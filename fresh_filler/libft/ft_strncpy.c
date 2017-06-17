/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:54:23 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/07 13:22:26 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;

	s = dst;
	while (0 < len && *src != '\0')
	{
		*s++ = *src++;
		--len;
	}
	while (0 < len)
	{
		*s++ = '\0';
		--len;
	}
	return (dst);
}
