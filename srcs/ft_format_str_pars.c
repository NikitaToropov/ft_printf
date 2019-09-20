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

int		is_it_parameter(char *str, a_list *list)
{
	char	*tmp;

	tmp = str;
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	if (*tmp == '$' && tmp != str)
	{
		list->parameter = ft_atoi(str);
		tmp++;
		return ((int)(tmp - str));
	}
	else
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

// int		is_it_width(char *str, a_list *list)
// {}

// char	ft_find_length(char *str, char type)
// {
// 	char	len;

// 	len = 0;
// 	while (*str != type)
// 	{
// 		if ((*str == 'l' && str[1] == 'l') ||
// 		(*str == 'h' && str[1] == 'h'))
// 		{
// 			if ((*str == 'l') && (str[1] == 'l'))
// 				len = 'L';
// 			if ((*str == 'h') && (str[1] == 'h'))
// 				len = 'H';
// 			str += 2;
// 		}
// 		else
// 		{
// 			if (*str == 'l')
// 				len = 'l';
// 			if (*str == 'h')
// 				len = 'h';
// 			str++;
// 		}		
// 	}
// 	return (len);
// }


// char	ft_find_flags(char *str, char type)
// {
// 	char	flags;
// 	// FLAGS:
// 	// 	HASH == (char)1;
// 	// 	ZERO == (char)2;
// 	// 	MINUS == (char)4;
// 	// 	MINUS == (char)8;
// 	// 	MINUS == (char)16;
// 	// 	APOSTROPHE == (char)32;

// 	flags = 0;
// 	while (*str != type)
// 	{
// 		if (*str == '#')
// 			flags |= 1;
// 		else if (*str == '0')
// 			flags |= 2;
// 		else if (*str == '-')
// 			flags |= 4;
// 		else if (*str == ' ')
// 			flags |= 8;
// 		else if (*str == '+')
// 			flags |= 16;
// 		else if (*str == '\'')
// 			flags |= 32;
// 		str++;			
// 	}
// 	if (type == 'c' || type == 'd' ||
// 	type == 'p' || type == 's')
// 		flags &= 62; //ignore flag '#'
// 	if (flags & 16)
// 		flags &= 47;
// 	return (flags);
// }

// void	ft_find_width_and_precission(char *str, a_list *list)
// {
// 	int			counter;
// 	char		*tmp;

// 	counter = 1;
// 	list->n_arg_width = 0;
// 	list->width = 0;
// 	list->n_arg_precision = 0;
// 	list->precision = 0;
// 	while (*str && *str != list->type)
// 	{
// 		if ((*str >= '0' && *str <= '9'))
// 		{
// 			tmp = str;
// 			while (*str >= '0' && *str <= '9')
// 				str++;
// 			if ()
// 			list->n_arg_width = 0;
// 			list->width = ft_atoi(str);
// 		}
// 		else if (*str == '*')
// 		{
// 			list->width = 0;
// 			list->n_arg_width = counter;
// 			str++;
// 			counter++;
// 		}
// 		else if (*str == '.')
// 		{
// 			str++;
// 			if (*str == '*')
// 			{
// 				list->precision = 0;
// 				list->n_arg_precision = counter;
// 				counter++;
// 				str++;
// 			}
// 			else if (*str >= '0' && *str <= '9')
// 			{
// 				list->n_arg_precision = 0;
// 				list->precision = ft_atoi(str);
// 				while (*str >= '0' && *str <= '9')
// 					str++;
// 			}
// 		}
// 		else
// 			str++;
// 	}
// }