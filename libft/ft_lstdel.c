/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:53:53 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:02 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && *alst && del)
	{
		while ((*alst)->next != NULL)
		{
			temp = (*alst)->next;
			ft_lstdelone(&(*alst), del);
			*alst = temp;
		}
		ft_lstdelone(&(*alst), del);
		(*alst) = NULL;
	}
}
