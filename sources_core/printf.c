/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:36:05 by fjenae            #+#    #+#             */
/*   Updated: 2019/09/17 21:11:41 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_printf(const		int	k, ...)

// {
// 	t_printf	*container;

// }	
// 	static char *ft_parse(char *arg)
// 	{
// 	}
// 	if (!container)
// 	{
// 		if(!(container = (t_printf *)malloc(sizeof(t_printf))))
// 			return (NULL);
// 	}
{
	va_list			args;
	char			value_pulled_from_ft;
	int				i;

	i = 0;
	va_start(args, k);
	while (i < 4)
	{
		value_pulled_from_ft = va_arg(args, int);
		// printf("number of variable %d: value of variable %d\n", i, value_pulled_from_ft);
		printf("%d\n", value_pulled_from_ft);
		// ft_parse(value_pulled_from_ft);
		i++;
	}
	va_end(args);
}

void	ft_test(int l)
{
	if (l == 5)
	{
		printf("firsttest_success\n");
		l++;
	}	
	while (l > 0)
	{
		printf("testsuccess\n");	
		l--;
	}
}