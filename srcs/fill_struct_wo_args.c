#include "ft_printf.h"

int		type_is_real(char c)
{
	if (c == 'c' || c == 's' ||
	c == 'p' || c == 'i' ||
	c == 'd' || c == 'u' ||
	c == 'o' || c == 'x' ||
	c == 'X' || c == 'f')
	// c == 'b' || c == 'r')
		return (1);
	return (0);
}

a_list		*make_blank_list(int counter)
{
	a_list		*list;

	if (!(list = malloc(sizeof(a_list))))
		ft_error(0);
	list->param_field = 0;
	list->parameter = counter;
	list->n_arg_width = 0;
	list->n_arg_precision = 0;
	list->n_arg = 0;

	list->width = -1;
	list->precision = -1;
	list->arg = NULL;

	list->flags = 0;
	list->length = 0;
	list->type = 0;

	list->next = NULL;
	return (list);
}

a_list		*fill_struct_wo_args(char *str)
{
	a_list			*first_list;
	a_list			*tmp_list;
	char			*tmp_str;
	
	first_list = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			str++;			
			if (!first_list)
			{
				first_list = make_blank_list(1);
				tmp_list = first_list;
			}
			else
			{
				tmp_list->next = make_blank_list(tmp_list->parameter);
				tmp_list = tmp_list->next;
			}
			tmp_list->type = find_type(str);
			while (*str != tmp_list->type)
			{
				tmp_str = str;
				str += is_it_width(str, tmp_list);
				str += is_it_parameter(str, tmp_list);
				str += is_it_precision(str, tmp_list);
				str += is_it_length(str, tmp_list);
				str += is_it_flag(*str, tmp_list);
				if (tmp_str == str)
				{
					tmp_list->type = *str;
					break ;
				}
			}
			if (type_is_real(tmp_list->type))
			{
				tmp_list->n_arg = tmp_list->parameter;
				tmp_list->parameter += 1;
			}
		}
		str++;
	}	
	return (first_list);
}