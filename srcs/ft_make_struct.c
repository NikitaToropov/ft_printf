#include "ft_printf.h"

a_list		*fill_struct_wo_args(char *str)
{
	a_list			*first;
	a_list			*tmp;
	unsigned int	counter;

	first = NULL;
	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			counter++;
			if (!first)
			{
				if (!(first = (a_list*)malloc(sizeof(a_list))))
					ft_error(0);
				tmp = first;
			}
			else
			{
				if (!(tmp->next = (a_list*)malloc(sizeof(a_list))))
					ft_error(0);
				tmp = tmp->next;
			}
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
	return (first_arg);
}