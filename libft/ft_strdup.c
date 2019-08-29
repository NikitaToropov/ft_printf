/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:33:14 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:36 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (s2 == 0)
		return (0);
	while (j <= i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}
