#include "ft_printf.h"

void	ft_put_int_arg(a_list *list, unsigned long long arg)
{
	if (list->type == 'd' || list->type == 'i')
		parse_simple_integer(list, arg);
	else if (list->type == 'u' || list->type == 'o' ||
	list->type == 'x' || list->type == 'X' || list->type == 'p')
	{
		parse_unsigned_integer(list, arg);
		// ft_itoa_base_uns(arg, list);
	}
	// else if (list->type == 'c')
	// else if (list->type == 's')
}