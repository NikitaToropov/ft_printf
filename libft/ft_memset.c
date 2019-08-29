/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:14:40 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:21 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *dst;

	dst = (unsigned char *)b;
	while (len)
	{
		*dst = (unsigned char)c;
		dst++;
		len--;
	}
	return (b);
}
