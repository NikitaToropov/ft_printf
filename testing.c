#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list					args;
	unsigned long long		num_of_symbls;

	va_start(args, format);
	ft_put	
	va_end(args);
	return (num_of_symbls);
}

int		main(void)
{
	int		num = 0;
	ft_printf("1243546789 %d\n", num);
	return (0);
}