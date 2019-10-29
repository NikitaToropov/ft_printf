	#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>


int		main(void)
{	
	long double		f = 1;

	// ft_printf("%Lf %i", f, 123456);
	ft_printf("%bLf, %i", f, 123);
	// printf("%lu", sizeof(int));

	return (0);
}