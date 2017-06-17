/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:11:55 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/15 14:48:38 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *str, char c)
{
	int flag;
	int count;

	flag = 0;
	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			count += flag;
			flag = 0;
		}
		else
			flag = 1;
		str++;
	}
	count += flag;
	return (count);
}
