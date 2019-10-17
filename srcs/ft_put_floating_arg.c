#include "ft_printf.h"

void	ft_parse_floating_arg(s_args *list, long double argument)
{
	short			exponent;
	unsigned int	integer_len;
	long double 	tmp;

	integer_len = 1;
	tmp = argument;
	exponent = (*((unsigned long long int*)c + 1) & 0x7FFF) - 0x3FFF;
}

void	ft_put_floating_arg(s_args *list, long double argument)
{
	double		double_argument;

	double_argument = (double)argument;
	if (list->flags & 64 && list->length == 'D')
		list->arg = ft_put_bits(&argument, sizeof(long double));
	else if (list->flags & 64 && list->length != 'D')
		list->arg = ft_put_bits(&double_argument, sizeof(double));
	else
	{
		ft_parse_floating_arg(lidt, argument);
	}
}