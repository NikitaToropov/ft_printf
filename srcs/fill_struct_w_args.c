#include "ft_printf.h"

int		find_latest_arg(a_list *list)
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

void	put_args_in_the_list(a_list *list, va_list ap, int	num_of_arg)
{
	unsigned long long	integer_arg;
	double				floating_arg;
	long double			long_floating_arg;

	integer_arg = 0;
	floating_arg = 0;
	long_floating_arg = 0;
	while (list)
	{
		if (list->n_arg == num_of_arg || list->n_arg_width == num_of_arg ||
		(list->n_arg == num_of_arg && 
		(list->type == 'i' || list->type == 'd' || list->type == 'c' ||
		list->type == 's' || list->type == 'x' || list->type == 'X' ||
		list->type == 'u' || list->type == 'o' || list->type == 'p')))
		{
			integer_arg = va_arg(ap, unsigned long long);
			break ;
		}
		if (list->n_arg == num_of_arg && list->type == 'f' && list->length != 'D')
		{
			floating_arg = va_arg(ap, double);
			break ;
		}
		if (list->n_arg == num_of_arg && list->type == 'f' && list->length == 'D')
		{
			long_floating_arg = va_arg(ap, long double);
			break ;
		}
		list = list->next;
	}
	while (list)
	{
		if (list->n_arg_width == num_of_arg)
		{
			list->width = (int)integer_arg;
			list->n_arg_width = 0;
		}
		if (list->n_arg_precision == num_of_arg)
		{
			list->precision = (int)integer_arg;
			list->n_arg_precision = 0;
		}
		if (list->n_arg == num_of_arg)
		{
			list->n_arg = 0;
			ft_put_int_arg(list, integer_arg);
			// if (list->type == 'f' && list->length != 'D')
			// 	ft_put_double_arg(list, floating_arg);
			// else if (list->type == 'f' && list->length = 'D')
			// 	ft_put_long_double_arg(list, long_floating_arg);
			// else
		}
		list = list->next;		
	}
}

void	fill_struct_w_args(a_list *list, va_list ap)
{
	int		latest_arg;
	int		counter_arg;

	latest_arg = find_latest_arg(list);
	counter_arg = 1;
	while (counter_arg <= latest_arg)
	{
		put_args_in_the_list(list, ap, counter_arg);
		counter_arg++;
	}
}