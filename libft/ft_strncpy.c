/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:05:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:44 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*res;

	res = dst;
	srclen = ft_strlen(src);
	i = 1;
	while (i <= len && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (srclen < len)
		while (i <= len)
		{
			*dst = '\0';
			dst++;
			i++;
		}
	return (res);
}
