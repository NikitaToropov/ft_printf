/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:38:50 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:26 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print(unsigned int n, int co, int sign)
{
	int				i;
	unsigned int	temp;
	unsigned int	div;

	i = 0;
	div = 1;
	while (i < co)
	{
		div = div * 10;
		i++;
	}
	temp = n;
	if (sign < 0)
		ft_putchar('-');
	i = 0;
	while (i <= co)
	{
		n = n / div;
		temp = temp % div;
		div = div / 10;
		ft_putchar(n + 48);
		n = temp;
		i++;
	}
}

void			ft_putnbr(int n)
{
	unsigned int	div;
	unsigned int	temp;
	int				co;
	int				sign;

	co = 0;
	div = 1;
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		temp = -n;
	}
	else
		temp = n;
	while (temp / div >= 10)
	{
		div = div * 10;
		co++;
	}
	ft_print(temp, co, sign);
}
