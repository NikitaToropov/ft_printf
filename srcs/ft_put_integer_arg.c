#include "ft_printf.h"

void	ft_put_integer_arg(a_list *list, unsigned long long arg)
{
	if (list->type == 'd' || list->type == 'i')
		parse_types_di(list, arg);
	if (list->type == 'u' || list->type == 'o' ||
	list->type == 'x' || list->type == 'X' || list->type == 'p')
		parse_types_uoxXp(list, arg);
	if (list->type == 'c')
		parse_type_c(list, arg);
	if (list->type == 's')
		parse_type_s(list, arg);
}