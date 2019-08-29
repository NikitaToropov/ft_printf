/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 23:46:56 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:30 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(char *str)
{
	int i;
	int count;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_isupper(str[i]))
			count++;
		i++;
	}
	if (i == count)
		return (1);
	return (0);
}
