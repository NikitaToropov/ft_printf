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

int		ft_check_the_type(char c)
{
	if (c == 'c' || c == 's' ||
	c == 'p' || c == 'i' ||
	c == 'd' || c == 'u' ||
	c == 'o' || c == 'x' ||
	c == 'X' || c == 'f')
		return (1);
	return (0);
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

s_args		*ft_format_string_parse(char *str)
{
	s_args			*first_list;
	s_args			*tmp_list;
	char			*tmp_str;
	
	first_list = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!first_list)
			{
				first_list = ft_make_blank_list(1);
				tmp_list = first_list;
			}
			else
			{
				tmp_list->next = ft_make_blank_list(tmp_list->parameter);
				tmp_list = tmp_list->next;
			}
			tmp_list->type = ft_find_type(str);
			while (*str != tmp_list->type)
			{
				tmp_str = str;
				str += ft_find_parameter(str, tmp_list);
				str += ft_find_width(str, tmp_list);
				str += ft_find_precision(str, tmp_list);
				str += ft_find_length(str, tmp_list);
				str += ft_find_flag(*str, tmp_list);
				if (tmp_str == str)
				{
					tmp_list->type = *str;
					break ;
				}
			}
			if (ft_check_the_type(tmp_list->type))
			{
				tmp_list->n_arg = tmp_list->parameter;
				tmp_list->parameter += 1;
			}
		}
		str++;
	}	
	return (first_list);
}