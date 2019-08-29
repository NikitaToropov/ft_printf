/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:08:48 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:42 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*core;

	i = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	else
		len = ft_strlen(s);
	if ((core = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
	{
		return (NULL);
	}
	else
	{
		while (s[i])
		{
			core[i] = ((f)(i, s[i]));
			i++;
		}
		core[i] = '\0';
	}
	return (core);
}
