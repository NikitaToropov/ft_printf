/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:48:23 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:34 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;
	int				res;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	res = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (res = str1[i] - str2[i]);
		i++;
	}
	return (0);
}
