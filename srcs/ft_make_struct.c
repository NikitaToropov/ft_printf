#include "ft_printf.h"

void	arg_me(va_list ap)
{
	long long	i;

	i = va_arg(ap, int);
	printf("|%lli|\n", i);
	i = va_arg(ap, int);
	printf("|%lli|\n", i);
	i = va_arg(ap, int);
	printf("|%lli|\n", i);
}

a_list		*ft_make_struct(const char *format, ...)
{
	va_list		ap;
	a_list		*first_arg;
	
	if (!(ft_strchr(format, '%')))
		return (NULL);
	first_arg = fill_struct_wo_args((char*)format);
	if (first_arg)
	{
    	va_start(ap, format);
		fill_struct_w_args(first_arg, ap);
		va_end(ap);
	}
	return (first_arg);
}