#include "ft_printf.h"

int		ft_find_parameter(char *str, s_args *list)
{
	char	*tmp_str;

	if (*str == '0')
		return (0);
	tmp_str = str;
	while (*tmp_str >= '0' && *tmp_str <= '9')
		tmp_str++;
	if (*tmp_str == '$')
	{
		list->parameter = ft_atoi(str);
		return (tmp_str - str + 1);
	}
	return (0);
}

int		ft_find_width(char *str, s_args *list)
{
	char	*tmp_str;

	if (str[0] == '0')
		return (0);
	if (str[0] == '*')
	{
		if ((str[1] >= '1' && str[1] <= '9') && str[2] == '$')
		{
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
	if (tmp_str != str)
	{
		list->width = ft_atoi(str);
		list->n_arg_width = 0;
		return (tmp_str - str);
	}
	return (0);
}

int		ft_find_precision(char *str, s_args *list)
{
	char	*tmp_str;

	if (str[0] != '.')
		return (0);
	if (str[1] == '*')
	{
		list->precision = -1;
		if ((str[2] >= '1' && str[2] <= '9') && str[3] == '$')
		{
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
	if (tmp_str != &str[1])
	{
		list->precision = ft_atoi(&str[1]);
		list->n_arg_precision = 0;
		return (tmp_str - str);
	}
	return (0);
}

int		ft_find_length(char *str, s_args *list)
{
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

int		ft_find_flag(char symbol, s_args *list)
{
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
	else if (symbol == 'b')
		list->flags |= 64;	
	// if (list->type == 'c' || list->type == 'd' ||
	// list->type == 'p' || list->type == 's' ||
	// list->type == 'i')
	// 	list->flags &= 254; //ignore flag '#'
	if (list->flags & 16) // if flag '+' then ignore ' '
		list->flags &= 247;
	if (symbol == '#' || symbol == '0' ||
	symbol == '-' || symbol == ' ' ||
	symbol == '+' || symbol == '\'' ||
	symbol == 'b')
		return (1);
	return (0);
}