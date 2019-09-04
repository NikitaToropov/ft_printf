#include "ft_printf.h"

// void	 fill_the_list(const char *str,  a_list *arg)
// {
// 	if (!arg)
// 	{
// 		if (!(arg = malloc(sizeof(a_list))))
// 			ft_error(1);
// 	}
// 	while ()
// }

// int			ft_print_and_count(a_list *first_arg, char *format)
// {
// 	return ();
// }

a_list		*fill_struct_wo_args(char *str)
{
	a_list			*first;
	a_list			*tmp;
	unsigned int	counter;

	first = NULL;
	counter = 0;
	while (str)
	{
		if (*str == '%')
		{
			counter++;
			if (!(tmp = (a_list*)malloc(sizeof(a_list))))
				ft_error(0);
			if (!first)
				first = tmp;
//one step to first modifier				
			str++;
//analising fields {%[parameter][flags][width][.precision][length]type}
			tmp->flags = '0' + counter;
			// str += put_parameter(str, $(tmp->parameter));
			// str += put_flags(str, $(tmp->flags));
			// str += put_width(str, $(tmp->width));
			// str += put_precision(str, $(tmp->precision));
			// str += put_lenght(str, $(tmp->lenght));
			// str += put_type(str, $(tmp->type));
			// tmp->type = NULL;
			tmp->next = NULL;
// jump to the next list 
			tmp = tmp->next;
		}
		else
			str++;
	}
	return (first);
}

a_list		*ft_make_struct(const char *format, ...)
{
	a_list		*first_arg;
	// va_list		args;
	
	if (!(ft_strchr(format, '%')))
		return (NULL);

	first_arg = fill_struct_wo_args((char*)format);

	// va_start(args, format);

	// va_end(args);

	return (first_arg);
	// if (!(first_arg = malloc(sizeof(a_list))))
	// 	ft_error(1);
	// if (ft_strchr(format, '%'))
	// {
	// 	tmp_arg = first_arg;
	// 	va_start(args, format);
	// 	while (*format)
	// 	{
	// 		if (*format == '%')
	// 		{
	// 			// fill_the_list(format, tmp_arg);
	// 			// tmp_arg  = tmp_arg->next;
	// 			printf("%s\n", format);
	// 		}
	// 		format++;
	// 	}
	// 	va_end(args);
		
	// 	return (first_arg);
	// }
	// else
}