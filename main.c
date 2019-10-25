#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>


int		main(void)
{	
	// double		f = 123.123;

	long double		f = -1234567890123456789012.12567l;		//dnt frgt


	ft_printf("%Lf %3$c %2$i", f, 1, '{');
	// for_arg("rtryr", 123.123L, 234.234L, 345.345L, 456.456L);
	return (0);
}