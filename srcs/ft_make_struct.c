#include "ft_printf.h"

a_list		*ft_make_blank_list(unsigned int num_of_list)
{
	a_list		*list;

	if (!(list = malloc(sizeof(a_list))))
		ft_error(0);
	list->width = -1; // don't know why BUT Check this shit!!!
	list->n_arg_width = 0;
	list->precision = -1; // don't know why BUT Check this shit!!!
	list->n_arg_precision = 0;

	list->length = 0;
	list->type = 0;
	list->arg = NULL;
	list->n_arg = 0;
	list->n_of_list = num_of_list;
	list->next = NULL;
	return (list);
}

a_list		*fill_struct_wo_args(char *str)
{
	a_list			*first_list;
	a_list			*tmp_list;
	unsigned int	num_of_list;
	char			*tmp_str;


	first_list = NULL;
	num_of_list = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++; // step after '%'
			num_of_list++;
			if (!first_list)
			{
				tmp_list = ft_make_blank_list(num_of_list);
				first_list = tmp_list;  
			}
			else
			{
				tmp_list->next = ft_make_blank_list(num_of_list);
				tmp_list = tmp_list->next;
			}
			
			tmp_list->type = ft_find_type(str);
			while (*str != tmp_list->type)
			{
				tmp_str = str;
				str += is_it_parameter(str, tmp_list);
				str += is_it_flag(*str, tmp_list);
				str += is_it_length(str, tmp_list);
				str += is_it_width(str, tmp_list);
				str += is_it_precission(str, tmp_list);

				if (tmp_str == str) // to exit the cyclсe 
				{	
					tmp_list->type = *str;
					break ;
				}
			}
			if (*str)
				str++;  // one step for step over the type
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