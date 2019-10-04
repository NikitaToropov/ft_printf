#include "ft_printf.h"

void	parse_types_di(a_list *list, unsigned long long argument)
{
	if (list->length == 'l')
		list->arg = ft_itoa((long int)argument);
	else if (list->length == 'L')
		list->arg = ft_itoa(argument);
	else if (list->length == 'h')
		list->arg = ft_itoa((short)argument);
	else if (list->length == 'H')
		list->arg = ft_itoa((char)argument);
	else
		list->arg = ft_itoa((int)argument);
}

void	parse_types_uo(a_list *list, unsigned long long argument)
{
	if (list->length == 'H')
	{
		if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned char)argument, 10);
		if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned char)argument, 8);
	}
	else if (list->length == 'h')
	{
		if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned short)argument, 10);
		if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned short)argument, 8);
	}
	else if (list->length == 'L')
	{
		if (list->type == 'u')
			list->arg = ft_itoa_base(argument, 10);
		if (list->type == 'o')
			list->arg = ft_itoa_base(argument, 8);
	}
	else if (list->length == 'l')
	{
		if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned long int)argument, 10);
		if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned long int)argument, 8);
	}
	else
	{
		if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned long int)argument, 10);
		if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned long int)argument, 8);
	}
}

void	parse_types_xXp(a_list *list, unsigned long long argument)
{
	if (list->type == 'p')
		list->arg = ft_itoa_pointer(argument);
	if (list->length == 'H')
	{
		if (list->type == 'x' || list->type == 'p')
			list->arg = ft_itoa_base((unsigned char)argument, 16);
		if (list->type == 'X')
			list->arg = ft_ITOA_base((unsigned char)argument, 16);
	}
	else if (list->length == 'h')
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned short)argument, 16);
		if (list->type == 'X')
			list->arg = ft_ITOA_base((unsigned short)argument, 16);
	}
	else if (list->length == 'L')
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned long long)argument, 16);
		if (list->type == 'X')
			list->arg = ft_ITOA_base((unsigned long long)argument, 16);
	}
	else if (list->length == 'l')
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned long)argument, 16);
		if (list->type == 'X')
			list->arg = ft_ITOA_base((unsigned long)argument, 16);
	}
	else
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned char)argument, 16);
		if (list->type == 'X')
			list->arg = ft_ITOA_base((unsigned char)argument, 16);
	}
}

void	ft_put_integer_arg(a_list *list, unsigned long long argument)
{
	if (list->type == 'd' || list->type == 'i')
		parse_types_di(list, argument);
	if (list->type == 'u' || list->type == 'o')
		parse_types_uo(list, argument);
	if (list->type == 'x' || list->type == 'X' || list->type == 'p')
		parse_types_xXp(list, argument);
	if (list->type == 'c')
		list->arg = ft_utf_8_coder((int)argument);
	if (list->type == 's')
		list->arg = (char*)argument;
}