/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:59:56 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:11 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*vars1;
	unsigned char	*vars2;
	size_t			i;
	int				res;

	vars1 = (unsigned char *)s1;
	vars2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (vars1[i] != vars2[i])
		{
			res = vars1[i] - vars2[i];
			return (res);
		}
		i++;
	}
	return (0);
}
