/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:11:13 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:50 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	int				length;
	int				i;

	if (s == NULL)
		return (NULL);
	length = (int)len;
	if (!(substr = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	while (i != length)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
