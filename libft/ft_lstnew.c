/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 23:26:17 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:06 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *node1;

	if (!(node1 = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node1->content = NULL;
		node1->content_size = 0;
	}
	else
	{
		if (!(node1->content = (t_list *)malloc(content_size)))
		{
			free(node1);
			return (NULL);
		}
		ft_memcpy(node1->content, content, content_size);
		node1->content_size = content_size;
	}
	node1->next = NULL;
	return (node1);
}
