#include "ft_printf.h"

a_list		*ft_make_struct(const char *format, ...)
{
	va_list		ap;
	a_list		*first_list;
	
	if (!(ft_strchr(format, '%')))
		return (NULL);
	first_list = fill_struct_wo_args((char*)format);
	ft_check_the_valid(first_list);
	if (first_list)
	{
    	va_start(ap, format);
		fill_struct_w_args(first_list, ap);
		va_end(ap);
	}
	return (first_list);
}