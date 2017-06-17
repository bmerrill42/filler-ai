/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 22:19:51 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/01 22:34:52 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*strcpy;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (!(strcpy = (char *)malloc(sizeof(char) * (src_size + 1))))
		return (NULL);
	strcpy = ft_strcpy(strcpy, src);
	return (strcpy);
}
