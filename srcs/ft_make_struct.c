#include "ft_printf.h"

a_list		*fill_struct_wo_args(char *str)
{
	a_list			*first_list;
	a_list			*tmp_list;
	unsigned int	counter;

	first_list = NULL;
	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			counter++;
			if (!first_list)
			{
				if (!(first_list = (a_list*)malloc(sizeof(a_list))))
					ft_error(0);
				tmp_list = first_list;
			}
			else
			{
				if (!(tmp_list->next = (a_list*)malloc(sizeof(a_list))))
					ft_error(0);
				tmp_list = tmp_list->next;
			}
			str++; //one step to first_list modifier				

			tmp_list->next = NULL;
			if (!(tmp_list->type = ft_find_type(str)) ||
			tmp_list->type == '%')
			{
				str++;
				continue;
			}
			tmp_list->n_of_list = counter;
			tmp_list->parameter = ft_find_parameter(str, tmp_list->type);
		}
		else
			str++;
	}
	return (first_list);
}

a_list		*ft_make_struct(const char *format, ...)
{
	a_list		*first_arg;

	if (!(ft_strchr(format, '%')))
		return (NULL);
	first_arg = fill_struct_wo_args((char*)format);
	return (first_arg);
}