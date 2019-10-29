#include "ft_printf.h"

char	ft_find_type(char *str)
{
	while (*str)
	{
		if (*str == 'c')
			return ('c');
		else if (*str == 's')
			return ('s');
		else if (*str == 'p')
			return ('p');
		else if (*str == 'i')
			return ('i');
		else if (*str == 'd')
			return ('d');
		else if (*str == 'u')
			return ('u');
		else if (*str == 'o')
			return ('o');
		else if (*str == 'x')
			return ('x');
		else if (*str == 'X')
			return ('X');
		else if (*str == 'f')
			return ('f');
		else if (*str == '%')
			return ('%');
		str++;
	}
	return ('\0');
}

s_args		*ft_make_blank_list(int counter)
{
	s_args		*list;

	if (!(list = malloc(sizeof(s_args))))
		ft_error(1);
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

char		*ft_format_string_parse(s_args *list, char *str)
{
	char			*tmp_str;

	list->type = ft_find_type(str);
	while (*str != list->type)
	{
		tmp_str = str;
		str += ft_find_parameter(str, list);
		str += ft_find_width(str, list);
		str += ft_find_precision(str, list);
		str += ft_find_length(str, list);
		str += ft_find_flag(*str, list);
		if (tmp_str == str)
		{
			list->type = *str;
			break ;
		}
	}
	if (tmp_str != str) // cause not UB
	{
		list->n_arg = list->parameter;
		list->parameter += 1;
	}
	return (str);
}

s_args		*ft_string_parse(char *str)
{
	s_args			*list;
	s_args			*first_list;
	
	first_list = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!first_list)
			{
				first_list = ft_make_blank_list(1);
				list = first_list;
			}
			else
			{
				list->next = ft_make_blank_list(list->parameter);
				list = list->next;
			}
			str = ft_format_string_parse(list, str);
		}
		str++;
	}
	return (first_list);
}