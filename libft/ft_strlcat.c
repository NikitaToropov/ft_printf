/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:39:58 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:39 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0 || size <= dstlen)
	{
		return (size + srclen);
	}
	if (size > dstlen)
	{
		dst = ft_strncat(dst, src, (size - dstlen - 1));
	}
	return (dstlen + srclen);
}
