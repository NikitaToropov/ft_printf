
#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

// void	 fill_the_list(const char *str,  a_list *arg)
// {
// 	if (!arg)
// 	{
// 		if (!(arg = malloc(sizeof(a_list))))
// 			ft_error(1);
// 	}
// 	while ()
// }

a_list		*ft_make_struct(const char *format, ...)
{
	a_list		*first_arg;
	a_list		*tmp_arg;
	va_list		args;

	if (ft_strchr(format, '%'))
	{
		if (!(first_arg = malloc(sizeof(a_list))))
			ft_error(1);
		tmp_arg = first_arg;
		va_start(args, format);
		while (*format)
		{
			if (*format == '%')
			{
				// fill_the_list(format, tmp_arg);
				// tmp_arg  = tmp_arg->next;
				printf("%s\n", format);
			}
			format++;
		}
		va_end(args);
		
		return (first_arg);
	}
	else
		return (NULL);
}

// int			ft_print_and_count(a_list *first_arg, char *format)
// {
// 	return ();
// }

int			ft_printf(const char *format, ...)
{
	a_list		*first_arg;
	int			num_of_chars;

	num_of_chars = 0;
	// ft_testing(format);
	// return (num_of_symbls);
	first_arg = ft_make_struct(format);
	// num_of_chars = ft_print_and_count(first_arg, format);
	// ft_clear_struct(&first_arg);
	return (num_of_chars);
}

// int		main(void)
// {
// 	int	i = 5, a = 7;
// 	ft_printf("change my pitch up %d samck my bitch up", 'a', 'b', 'c', 'd');
// 	// printf("change my pitch up %d;\n%d,\n%d.", i, a);

// 	return (0);
// }