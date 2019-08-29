/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 22:41:59 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:43 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*result;
	size_t	limit;

	result = s1;
	limit = ft_strlen(s2);
	if (limit < n)
		n = limit;
	while (*s1 != '\0')
		s1++;
	while (n > 0)
	{
		*s1 = *s2;
		s2++;
		s1++;
		n--;
	}
	*s1 = '\0';
	return (result);
}
