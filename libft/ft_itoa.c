/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:08:40 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:58:45 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_print(char *s, int sign, int counter, int n)
{
	int				i;
	size_t			temp;

	if (sign < 0)
		s[0] = '-';
	temp = 1;
	if (sign < 0)
		i = 2;
	else
		i = 1;
	while (i++ < counter)
		temp = temp * 10;
	if (sign < 0)
		i = 1;
	else
		i = 0;
	while (i < counter)
	{
		s[i] = (n / temp) + 48;
		n = n % temp;
		temp = temp / 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char			*s;
	int				counter;
	unsigned int	temp;
	int				sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	counter = n == 0 ? 1 : 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
		counter++;
	}
	temp = n;
	while (temp >= 1)
	{
		temp = temp / 10;
		counter++;
	}
	if (!(s = (char *)malloc(sizeof(char) * (counter + 1))))
		return (NULL);
	return (ft_print(s, sign, counter, n));
}
