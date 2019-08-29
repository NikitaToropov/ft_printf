/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 06:34:30 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:47 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	m;
	int		i;
	char	*ar;

	ar = (char*)s;
	m = (char)c;
	i = ft_strlen(s);
	if (m == '\0')
	{
		while (s[i])
			i--;
		return (ar + i);
	}
	while (i >= 0)
	{
		if (m == s[i])
			return (ar + i);
		i--;
	}
	return (NULL);
}
