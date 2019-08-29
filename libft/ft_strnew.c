/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:02:44 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:46 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *result;

	if ((size + 1 < size) || !(result = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}
