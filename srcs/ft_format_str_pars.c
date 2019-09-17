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
			// str--;
			while (*str == '$' || (*str >= '0' && *str <= '9'))
				str--;
			str++;
			return (ft_atoi(str));
		}
		else
			str--;
	}
	return (0);
}