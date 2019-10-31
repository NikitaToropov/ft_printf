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

char	ft_selector_of_types(s_args *list, int counter_arg)
{
	while (list)
	{
		if (list->n_arg_width == counter_arg ||
		list->n_arg_precision == counter_arg ||
		(list->n_arg == counter_arg && ft_check_integer_type(list->type)))
		{
			return ('i');
		}
		if (list->n_arg == counter_arg && list->type == 'f' &&
		list->length != 'F')
		{
			return ('f');
		}
		if (list->n_arg == counter_arg && list->type == 'f' &&
		list->length == 'F')
		{
			return ('F');
		}
		list = list->next;
	}
	return ('e');
}

void	ft_put_the_arg_in_lists(s_args *list, int num, unsigned long long integer_arg, long double floating_arg)
{

	while (list)
	{
		if (list->n_arg_width == num && list->width == -1)
			list->width = (int)integer_arg;
		if (list->n_arg_precision == num && list->precision == -1)
			list->precision = (int)integer_arg;
		if (list->n_arg == num)
		{
			if (list->flags & BIN_FLAG &&
			(list->type == 'd' || list->type == 'i' || list->type == 'u' ||
			list->type == 'c' || list->type == 'f'))
			{
				if (integer_arg)
					ft_put_bits(&integer_arg, list);
				else
					ft_put_bits(&floating_arg, list);
			}
			else if (ft_check_integer_type(list->type))
				ft_put_integer_arg(list, integer_arg);
			else if (list->type == 'f')
				ft_put_floating_arg(list, floating_arg);
		}
		list = list->next;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list					ap;
	s_args					*first_list;
	char					type_selector;
	int						num_of_ltst_arg;
	int						counter_arg;


	first_list = ft_string_parse((char*)format);
	if (first_list)
	{
		va_start(ap, format);
		num_of_ltst_arg = ft_find_ltst_arg(first_list);
		counter_arg = 1;
		while (counter_arg <= num_of_ltst_arg)
		{
			type_selector = ft_selector_of_types(first_list, counter_arg);
			if (type_selector == 'i')
				ft_put_the_arg_in_lists(first_list, counter_arg, va_arg(ap, unsigned long long), 0);
			else if (type_selector == 'f')
				ft_put_the_arg_in_lists(first_list, counter_arg, 0, (long double)va_arg(ap, double));
			else if (type_selector == 'F')
				ft_put_the_arg_in_lists(first_list, counter_arg, 0, va_arg(ap, long double));
			else
				va_arg(ap, long long int);
			counter_arg++;

		}
		va_end(ap);
		ft_modify_str_arg(first_list);
	}
	
	while (first_list)
	{
		printf("\n\"parameter\"         is '%d'\n", first_list->parameter);
		printf("\"n_arg_width\"       is '%d'\n", first_list->n_arg_width);
		printf("\"n_arg_precision\"   is '%d'\n", first_list->n_arg_precision);
		printf("\"n_arg\"             is '%d'\n\n", first_list->n_arg);

		printf("\"width\"             is '%d'\n", first_list->width);
		printf("\"precision\"         is '%d'\n", first_list->precision);
		printf("\"arg\"               is '%s'\n\n", first_list->arg);
		
		printf("\"flags\"             is '%i'\n", first_list->flags);
		printf("\"length\"            is '%c'\n", first_list->length);
		printf("\"type\"              is '%c'\n", first_list->type);
		printf("------------------------------------\n\n");


		first_list = first_list->next;
	}


	ft_clear_the_struct(&first_list);
	return (0);
}