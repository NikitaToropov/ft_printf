#include "ft_printf.h"

char	find_type(char *str)
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
		// else if (*str == 'b')
		// 	return ('b');
		// else if (*str == 'r')
		// 	return ('r');
		// else if (*str == 'k')
		// 	return ('k');
		str++;
	}
	return ('\0');
}

int		is_it_parameter(char *str, a_list *list)
{
	if ((str[0] >= '1' && str[0] <= '9' && str[1] == '$'))
	{
		list->param_field = 1;
		list->parameter = str[0] - '0';
		return (2);
	}
	return (0);
}

int		is_it_width(char *str, a_list *list)
{
	char	*tmp_str;

	if (str[0] == '0')
		return (0);
	if (str[0] == '*')
	{
		list->width = -1;
		if ((str[1] >= '1' && str[1] <= '9') && str[2] == '$')
		{
			list->param_field = 1;
			list->n_arg_width = str[1] - '0';
			return (3);
		}
		else
		{
			list->n_arg_width = list->parameter;
			list->parameter += 1;
			return (1);
		}
	}
	tmp_str = str;
	while (*tmp_str >= '0' && *tmp_str <= '9')
		tmp_str++;
	if (tmp_str != str && *tmp_str != '$' && *tmp_str != '.')
	{
		list->width = ft_atoi(str);
		list->n_arg_width = 0;
		return (tmp_str - str);
	}
	return (0);
}

int		is_it_precision(char *str, a_list *list)
{
	char	*tmp_str;

	if (str[0] != '.' || str[1] == '0')
		return (0);
	if (str[1] == '*')
	{
		list->precision = -1;
		if ((str[2] >= '1' && str[2] <= '9') && str[3] == '$')
		{
			list->param_field = 1;
			list->n_arg_precision = str[2] - '0';
			return (4);
		}
		else
		{
			list->n_arg_precision = list->parameter;
			list->parameter += 1;
			return (2);
		}
	}	
	tmp_str = &str[1];
	while (*tmp_str >= '0' && *tmp_str <= '9')
		tmp_str++;
	if (tmp_str != str)
	{
		list->precision = ft_atoi(&str[1]);
		list->n_arg_precision = 0;
		return (tmp_str - str);
	}
	return (0);
}

int		is_it_length(char *str, a_list *list)
{
// 'H' == "hh"
// 'h' == "h"
// 'L' == "ll"
// 'l' == "l"

	if (!*str)
		return (0);
	else if (str[0] == 'h' && str[1] == 'h')
	{
		list->length = 'H';
		return (2);
	}
	else if (str[0] == 'l' && str[1] == 'l')
	{
		list->length = 'L';
		return (2);
	}
	else if (str[0] == 'h')
	{
		list->length = 'h';
		return (1);
	}
	else if (str[0] == 'l')
	{
		list->length = 'l';
		return (1);
	}
	else if (str[0] == 'L')
	{
		list->length = 'F';
		return (1);
	}
	return (0);
}

int		is_it_flag(char symbol, a_list *list)
{
//FLAGS:
// 	HASH == (char)1;
// 	ZERO == (char)2;
// 	MINUS == (char)4;
// 	SPACE == (char)8;
// 	PLUS == (char)16;
// 	APOSTROPHE == (char)32;
	if (symbol == '#')
		list->flags |= 1;
	else if (symbol == '0')
		list->flags |= 2;
	else if (symbol == '-')
		list->flags |= 4;
	else if (symbol == ' ')
		list->flags |= 8;
	else if (symbol == '+')
		list->flags |= 16;
	else if (symbol == '\'')
		list->flags |= 32;
	
	if (list->type == 'c' || list->type == 'd' ||
	list->type == 'p' || list->type == 's' ||
	list->type == 'i')
		list->flags &= 62; //ignore flag '#'
	if (list->flags & 16) // if flag '+' then ignore ' '
		list->flags &= 55;
	if (symbol == '#' || symbol == '0' ||
	symbol == '-' || symbol == ' ' ||
	symbol == '+' || symbol == '\'')
		return (1);
	return (0);
}

// void	put_n_arg(a_list *list)
// {
// 	if (list->selector == 'w')
// 		list->n_arg = list->n_arg_width + 1;
// 	else if (list->selector == 'p')
// 		list->n_arg = list->n_arg_precision + 1;
// 	else
// 		list->n_arg = list->parameter;
// 	if (list->width != -1)
// 		list->n_arg_width = 0;
// 	if (list->precision != -1)
// 		list->n_arg_precision = 0;
// }