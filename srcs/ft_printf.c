
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

// ft_type_of_arg()
// {

// }

int			ft_printf(const char *format, ...)
{
	va_list					ap;
	s_args					*first_list;
	s_args					*tmp_list;
	int						num_of_ltst_arg;
	int						counter_arg;
	unsigned long long		integer_arg;
	long double				long_floating_arg;


	first_list = NULL;
	if (ft_strchr(format, '%'))
	{
		first_list = ft_format_string_parse((char*)format);
		va_start(ap, format);

		num_of_ltst_arg = ft_find_ltst_arg(first_list);
		counter_arg = 1;
		while (counter_arg <= num_of_ltst_arg)
		{
			tmp_list = first_list;
			while (tmp_list)
			{
				if (tmp_list->n_arg_width == counter_arg ||
				tmp_list->n_arg_precision == counter_arg ||
				(tmp_list->n_arg == counter_arg && ft_check_integer_type(tmp_list->type)))
				{
					integer_arg = va_arg(ap, unsigned long long);
					break ;
				}
				if (tmp_list->n_arg == counter_arg && tmp_list->type == 'f' &&
				tmp_list->length != 'F')
				{
					long_floating_arg = (long double)va_arg(ap, double);
					break ;
				}
				if (tmp_list->n_arg == counter_arg && tmp_list->type == 'f' &&
				tmp_list->length == 'F')
				{
					long_floating_arg = (long double)va_arg(ap, long double);
					break ;
				}
				tmp_list = tmp_list->next;
			}
			while (tmp_list) 
			{
				if (tmp_list->n_arg_width == counter_arg)
					tmp_list->width = (int)integer_arg;
				if (tmp_list->n_arg_precision == counter_arg)
					tmp_list->precision = (int)integer_arg;
				if (tmp_list->n_arg == counter_arg)
				{
					if (ft_check_integer_type(tmp_list->type))
						ft_put_integer_arg(tmp_list, integer_arg);
					if (tmp_list->type == 'f')
						ft_put_floating_arg(tmp_list, long_floating_arg);
				}
				tmp_list = tmp_list->next;
			}
			counter_arg++;
		}
		va_end(ap);
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