/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:29:03 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/15 14:51:17 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**out;
	int		twodindex;
	int		strindex;

	if (!s ||
	!(out = (char **)malloc(sizeof(char *) * ft_wordcount(s, c) + 1)))
		return (NULL);
	twodindex = 0;
	strindex = 0;
	while (twodindex < ft_wordcount(s, c))
	{
		while (s[strindex] == c)
			strindex++;
		out[twodindex] = ft_strnew(ft_strcspn(&s[strindex], c));
		if (!out[twodindex])
			return (NULL);
		ft_strncpy(out[twodindex], &s[strindex], ft_strcspn(&s[strindex], c));
		out[twodindex][ft_strcspn(&s[strindex], c)] = '\0';
		while (s[strindex] != c && s[strindex] != '\0')
			strindex++;
		twodindex++;
	}
	out[twodindex] = NULL;
	return (out);
}
