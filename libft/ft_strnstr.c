/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:08:51 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:47 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_core(char *h, char *n, size_t len, size_t lenl)
{
	size_t	i;
	size_t	m;
	size_t	g;
	size_t	lens;

	i = 0;
	m = 0;
	g = 0;
	lens = ft_strlen(n);
	while (i < lenl && i < len && g < len)
	{
		while (m < lens && h[i] == n[m])
		{
			i++;
			m++;
		}
		if (m == lens && g + lens <= len)
			return (h + i - m);
		{
			i = i + 1 - m;
			m = 0;
		}
		g++;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*h;
	char		*n;
	size_t		lenl;
	size_t		lens;

	h = (char *)haystack;
	n = (char *)needle;
	lenl = ft_strlen(h);
	lens = ft_strlen(n);
	if (lens == 0)
		return (h);
	return (ft_core(h, n, len, lenl));
}
