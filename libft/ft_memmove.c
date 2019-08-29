/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:10:02 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:15 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*vardst;
	unsigned char	*varsrc;
	size_t			i;

	vardst = (unsigned char *)dst;
	varsrc = (unsigned char *)src;
	i = -1;
	if (varsrc < vardst)
	{
		while (len--)
			vardst[len] = varsrc[len];
	}
	else if (varsrc > vardst)
	{
		while (++i < len)
			vardst[i] = varsrc[i];
	}
	return (dst);
}
