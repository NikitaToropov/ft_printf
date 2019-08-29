/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 22:19:56 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:35 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptrdst;

	ptrdst = dst;
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (ptrdst);
}
