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

put_args_in_the_list(a_list *list, va_list ap)

void	fill_struct_w_args(a_list *list, va_list ap)
{
	// a_list		*tmp_list;

	while (list)
	{
		put_args_in_the_list(lsit, ap);
		list = list->next;
	}
	put_the_arg(first_list, ap, counter);
}