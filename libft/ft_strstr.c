/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 13:28:27 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:49 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_core(char *h, const char *n, int lenl, int lens)
{
	int			i;
	int			m;

	i = 0;
	m = 0;
	while (i < lenl)
	{
		while (m < lens && h[i] == n[m])
		{
			m++;
			i++;
		}
		if (m == lens)
			return (h + i - m);
		else
		{
			i = i + 1 - m;
			m = 0;
		}
	}
	return (NULL);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int			lenhaystack;
	int			lenneedle;
	char		*temph;

	temph = (char *)haystack;
	lenhaystack = ft_strlen(haystack);
	lenneedle = ft_strlen(needle);
	if (lenneedle == 0)
		return (temph);
	else
		return (ft_core(temph, needle, lenhaystack, lenneedle));
}
