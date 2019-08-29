/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:43:40 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:09 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*vardst;
	unsigned char		*varsrc;
	unsigned char		chk;
	size_t				i;

	chk = (unsigned char)c;
	i = 0;
	vardst = (unsigned char *)dst;
	varsrc = (unsigned char *)src;
	while (i < n)
	{
		vardst[i] = varsrc[i];
		if (chk == varsrc[i])
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
