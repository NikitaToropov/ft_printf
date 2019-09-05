/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:36:05 by fjenae            #+#    #+#             */
/*   Updated: 2019/09/05 21:44:44 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printf(int	k, ...)
{
	va_list	args;
	int		value_pulled_from_ft;
	int		i;

	i = 0;
	va_start(args, k);
	while (i < k)
	{
		value_pulled_from_ft = va_arg(args, int);
		// printf("number of variable %d: value of variable %d\n", i, value_pulled_from_ft);
		printf("%d\n", value_pulled_from_ft);
		i++;
	}
	va_end(args);
}