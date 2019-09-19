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
		else if (*str == 'i' || *str == 'd')
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

unsigned int	ft_find_parameter(char *str, char type)
{	
	while (*str != type)
		str++;
	while (*str != '%')
	{
		if (*str == '$')
		{
			str--;
			while (*str >= '0' && *str <= '9')
				str--;
			str++;
			return (ft_atoi(str));
		}
		else
			str--;
	}
	return (0);
}

char	ft_find_length(char *str, char type)
{
	char	len;

	len = 0;
	while (*str != type)
	{
		if ((*str == 'l' && str[1] == 'l') ||
		(*str == 'h' && str[1] == 'h'))
		{
			if ((*str == 'l') && (str[1] == 'l'))
				len = 'L';
			if ((*str == 'h') && (str[1] == 'h'))
				len = 'H';
			str += 2;
		}
		else
		{
			if (*str == 'l')
				len = 'l';
			if (*str == 'h')
				len = 'h';
			str++;
		}		
	}
	return (len);
}

char	ft_find_flags(char *str, char type)
{
	char	flags;
	// FLAGS:
	// 	HASH == (char)1;
	// 	ZERO == (char)2;
	// 	MINUS == (char)4;
	// 	MINUS == (char)8;
	// 	MINUS == (char)16;
	// 	APOSTROPHE == (char)32;

	flags = 0;
	while (*str != type)
	{
		printf("YO!\n");
		if (*str == '#')
			flags |= 1;
		else if (*str == '0')
			flags |= 2;
		else if (*str == '-')
			flags |= 4;
		else if (*str == ' ')
			flags |= 8;
		else if (*str == '+')
			flags |= 16;
		else if (*str == '\'')
			flags |= 32;
		str++;			
	}
	if (type == 'c' || type == 'd' ||
	type == 'p' || type == 's')
		flags &= 62; //ignore flag '#'
	if (flags & 16)
		flags &= 47;
	return (flags);
}
