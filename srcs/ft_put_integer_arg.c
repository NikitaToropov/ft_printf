#include "ft_printf.h"

void	ft_parse_types_di(s_args *list, unsigned long long argument)
{
	if (list->length == 'l')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(long int));
		else
			list->arg = ft_itoa((long int)argument);
	}
	else if (list->length == 'L')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(long long int));
		else
			list->arg = ft_itoa(argument);
	}
	else if (list->length == 'h')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(short));
		else
			list->arg = ft_itoa((short)argument);
	}
	else if (list->length == 'H')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(char));
		else
			list->arg = ft_itoa((char)argument);
	}
	else
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(int));
		else
			list->arg = ft_itoa((int)argument);
	}
}

void	ft_parse_types_uo(s_args *list, unsigned long long argument)
{
	if (list->length == 'H')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(char));
		else if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned char)argument, 10);
		else if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned char)argument, 8);
	}
	else if (list->length == 'h')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(short));
		else if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned short)argument, 10);
		else if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned short)argument, 8);
	}
	else if (list->length == 'L')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(long long int));
		else if (list->type == 'u')
			list->arg = ft_itoa_base(argument, 10);
		else if (list->type == 'o')
			list->arg = ft_itoa_base(argument, 8);
	}
	else if (list->length == 'l')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(long int));
		else if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned long int)argument, 10);
		else if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned long int)argument, 8);
	}
	else
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(int));
		else if (list->type == 'u')
			list->arg = ft_itoa_base((unsigned int)argument, 10);
		else if (list->type == 'o')
			list->arg = ft_itoa_base((unsigned int)argument, 8);
	}
}

void	ft_parse_types_xXp(s_args *list, unsigned long long argument)
{
	if (list->type == 'p')
		list->arg = ft_itoa_pointer(argument);
	if (list->length == 'H')
	{
		if (list->type == 'x' || list->type == 'p')
			list->arg = ft_itoa_base((unsigned char)argument, 16);
		if (list->type == 'X')
			list->arg = ft_itoa_base_uppercase((unsigned char)argument, 16);
	}
	else if (list->length == 'h')
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned short)argument, 16);
		if (list->type == 'X')
			list->arg = ft_itoa_base_uppercase((unsigned short)argument, 16);
	}
	else if (list->length == 'L')
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned long long)argument, 16);
		if (list->type == 'X')
			list->arg = ft_itoa_base_uppercase((unsigned long long)argument, 16);
	}
	else if (list->length == 'l')
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned long)argument, 16);
		if (list->type == 'X')
			list->arg = ft_itoa_base_uppercase((unsigned long)argument, 16);
	}
	else
	{
		if (list->type == 'x')
			list->arg = ft_itoa_base((unsigned char)argument, 16);
		if (list->type == 'X')
			list->arg = ft_itoa_base_uppercase((unsigned char)argument, 16);
	}
}

void	ft_put_integer_arg(s_args *list, unsigned long long argument)
{
	if (list->type == 'd' || list->type == 'i')
		ft_parse_types_di(list, argument);
	if (list->type == 'u' || list->type == 'o')
		ft_parse_types_uo(list, argument);
	if (list->type == 'x' || list->type == 'X' || list->type == 'p')
		ft_parse_types_xXp(list, argument);
	if (list->type == 'c')
	{
		if (list->flags & 64)
			list->arg = ft_put_bits(&argument, sizeof(char));
		else
			list->arg = ft_utf_8_coder((int)argument);
	}
	if (list->type == 's')
		list->arg = (char*)argument;
}