/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:38:04 by fjenae            #+#    #+#             */
/*   Updated: 2019/09/17 21:08:24 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_printf
{
	char    		type;
    // char            original;
	struct s_listg	*next;
}					t_printf;

void	ft_printf(const int first, ...);
void	ft_test(int l);

#endif