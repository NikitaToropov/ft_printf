/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:59:36 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:10 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*vars;
	unsigned char	check;
	size_t			i;

	vars = (unsigned char *)s;
	check = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (vars[i] == check)
			return ((void *)(vars + i));
	}
	return (NULL);
}
