/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 05:31:35 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:32 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	m;
	int		i;
	char	*ar;

	ar = (char*)s;
	m = (char)c;
	i = 0;
	if (m == '\0')
	{
		while (s[i])
			i++;
		return (ar + i);
	}
	while (s[i])
	{
		if (m == s[i])
			return (ar + i);
		i++;
	}
	return (NULL);
}
