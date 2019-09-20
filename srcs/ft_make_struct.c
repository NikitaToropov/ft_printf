#include "ft_printf.h"

a_list		*ft_make_blank_list(unsigned int num_of_list)
{
	a_list		*list;

	if (!(list = malloc(sizeof(a_list))))
		ft_error(0);
	list->width = 0;
	list->n_arg_width = 0;
	list->precision = 0;
	list->n_arg_precision = 0;

	list->length = 0;
	list->type = 0;
	list->arg = NULL;
	list->n_arg = 0;
	list->n_of_list = num_of_list;
	list->next = NULL;
	return (list);
}

// a_list		*fill_struct_wo_args(char *str)
// {
// 	a_list			*first_list;
// 	a_list			*tmp_list;
// 	unsigned int	counter;

// 	first_list = NULL;
// 	counter = 0;
// 	while (*str)
// 	{
// 		if (*str == '%')
// 		{
// 			counter++;
// 			if (!first_list)
// 			{
// 				if (!(first_list = (a_list*)malloc(sizeof(a_list))))
// 					ft_error(0);
// 				tmp_list = first_list;
// 			}
// 			else
// 			{
// 				if (!(tmp_list->next = (a_list*)malloc(sizeof(a_list))))
// 					ft_error(0);
// 				tmp_list = tmp_list->next;
// 			}
// 			str++; //one step to first_list modifier
// 			tmp_list->next = NULL;
// 			if (!(tmp_list->type = ft_find_type(str)) ||
// 			tmp_list->type == '%')
// // 			{
// // // НЕ ЗАБУДЬ ЗАНУЛИТЬ ВСЕ ПОЛЯ В ЭТОМ СЛУЧАЕ
// // 				while (*str && *str != '%')
// // 					str++;
// // 				str++;
// // 				continue;
// // 			}
// // 			tmp_list->n_of_list = counter;
// // 			tmp_list->parameter = ft_find_parameter(str, tmp_list->type);
// // 			tmp_list->length = ft_find_length(str, tmp_list->type);
// // 			tmp_list->flags = ft_find_flags(str, tmp_list->type);
// 		}
// 		else
// 			str++;
// 	}
// 	return (first_list);
// }

a_list		*fill_struct_wo_args(char *str)
{
	a_list			*first_list;
	a_list			*tmp_list;
	unsigned int	num_of_list;
	unsigned int	args_counter;
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
				first_list = ft_make_blank_list(num_of_list);
				tmp_list = first_list; 
			}
			else
			{
				tmp_list->next = ft_make_blank_list(num_of_list);
				tmp_list = tmp_list->next;
			}
			tmp_list->type = ft_find_type(str);
			if (!tmp_list->type)
				return (first_list);
			else if (tmp_list->type == '%')
			{
				while (*str != '%')
					str++;
				str++;
			}
			else
			{
				args_counter = 1;
				tmp_str = str;
				while (*str != tmp_list->type)
				{
					str += is_it_parameter(str, tmp_list);
					str += is_it_flag(*str, tmp_list);
					// str += is_it_width(str, tmp_list);
					// str += is_it_precission;
					// str += is_it_length;

					if (tmp_str == str)
					{
						tmp_list->type = 0;
						break ;
					}

					// printf("YOYOYOY   %s\n\n", str);
				}
			}
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