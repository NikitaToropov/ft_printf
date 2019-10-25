#include "ft_printf.h"

s_args		*ft_make_struct(const char *format, ...)
{
	va_list		ap;
	s_args		*first_list;
	
	if (!(ft_strchr(format, '%')))
		return (NULL);
	first_list = ft_format_string_parse((char*)format);
	if (first_list)
	{
		va_start(ap, format);
		ft_args_parse(first_list, ap);
		va_end(ap);
	}
	return (first_list);
}