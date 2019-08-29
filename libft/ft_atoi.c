/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:16:46 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:58:33 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_of(long c, const char *str, int sign, long i)
{
	long int	check;
	long int	comp;
	long int	orig;

	check = (long)c;
	comp = (long)c;
	orig = (long)c;
	check = (check * 10) + (long)(str[i] - '0');
	comp = ((check - ((long)(str[i] - '0'))) / 10);
	if (comp == orig)
		return (1);
	else
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
}

int			ft_atoi(const char *str)
{
	long	res;
	int		sign;
	long	i;

	res = 0;
	sign = +1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (ft_of(res, str, sign, i) == 0 || ft_of(res, str, sign, i) == -1)
			return (ft_of(res, str, sign, i));
		i++;
	}
	return ((int)(res * sign));
}
