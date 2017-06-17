/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:19:43 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/16 11:53:42 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *output;

	if (!(output = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		output->content = NULL;
		output->content_size = 0;
		output->next = NULL;
		return (output);
	}
	if (!(output->content = malloc(content_size)))
		return (NULL);
	else
	{
		ft_memcpy(output->content, content, content_size);
		output->content_size = content_size;
	}
	output->next = NULL;
	return (output);
}
