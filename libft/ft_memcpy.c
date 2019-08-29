/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:39:37 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:11 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*vardest;
	const char	*varsrc;

	if ((!dst && !src))
		return (NULL);
	vardest = (char *)dst;
	varsrc = (const char *)src;
	while (n)
	{
		*(vardest++) = *(varsrc++);
		n--;
	}
	return (dst);
}
