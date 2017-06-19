/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:44:18 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/14 17:10:54 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *string1, const char *string2)
{
	const unsigned char	*stringcopy1;
	const unsigned char	*stringcopy2;
	unsigned char		char1;
	unsigned char		char2;

	stringcopy1 = (const unsigned char *)string1;
	stringcopy2 = (const unsigned char *)string2;
	char1 = 0;
	char2 = 0;
	while (char1 == char2)
	{
		char1 = (unsigned char)*stringcopy1++;
		char2 = (unsigned char)*stringcopy2++;
		if (char1 == '\0')
			return (char1 - char2);
	}
	return (char1 - char2);
}
