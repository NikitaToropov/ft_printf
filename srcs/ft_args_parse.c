#include "ft_printf.h"

int		ft_check_integer_type(char type)
{
	if (type == 'c' || type == 's' || type == 'p' ||
	type == 'd' || type == 'i' || type == 'o' ||
	type == 'u' || type == 'x' || type == 'X')
		return (1);
	return (0);
}

int		ft_find_ltst_arg(s_args *list)
{
	int		biggest;

	biggest = 0;
	while (list)
	{
		if (biggest < list->n_arg_width)
			biggest = list->n_arg_width;
		if (biggest < list->n_arg_precision)
			biggest = list->n_arg_precision;
		if (biggest < list->n_arg)
			biggest = list->n_arg;
		list = list->next;
	}
	return (biggest);
}

void	put_args_in_the_list(s_args *list, va_list ap, int	num_of_arg)
{
	// s_args					*tmp_list;
	unsigned long long		integer_arg;
	double					floating_arg;
	long double				long_floating_arg;

	integer_arg = 0;
	floating_arg = 0;
	long_floating_arg = 0;
	while (list)
	{
		if (list->n_arg_width == num_of_arg ||
		list->n_arg_precision == num_of_arg ||
		(list->n_arg == num_of_arg && ft_check_integer_type(list->type)))
		{
			integer_arg = va_arg(ap, unsigned long long);
			floating_arg = (double)integer_arg;
			long_floating_arg = (long double)integer_arg;
			break ;
		}
		if (list->n_arg == num_of_arg && list->type == 'f' &&
		list->length != 'D')
		{
			floating_arg = va_arg(ap, double);
			integer_arg = (unsigned long long)floating_arg;
			long_floating_arg = (long double)floating_arg;
			break ;
		}
		if (list->n_arg == num_of_arg && list->type == 'f' &&
		list->length == 'D')
		{
			long_floating_arg = va_arg(ap, long double);
			integer_arg = (unsigned long long)long_floating_arg;
			floating_arg = (double)long_floating_arg;
			break ;
		}
		list = list->next;
	}
	while (list) 
	{
		if (list->n_arg_width == num_of_arg)
			list->width = (int)integer_arg;
		if (list->n_arg_precision == num_of_arg)
			list->precision = (int)integer_arg;
		if (list->n_arg == num_of_arg)
		{
			if (ft_check_integer_type(list->type))
				ft_put_integer_arg(list, integer_arg);
			// if (list->type == 'f')
			// 	ft_put_floating_arg(list, long_floating_arg);
		}
		list = list->next;
	}
}

void	ft_args_parse(s_args *list, va_list ap)
{
	int		num_of_ltst_arg;
	int		counter_arg;

	num_of_ltst_arg = ft_find_ltst_arg(list);
	counter_arg = 1;
	while (counter_arg <= num_of_ltst_arg)
	{
		put_args_in_the_list(list, ap, counter_arg);
		counter_arg++;
	}
}