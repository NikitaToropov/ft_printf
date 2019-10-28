	#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>


int		main(void)
{	
	// double		f = 123.123;

	// long double		f = -0;
	// int		f = 123;
	long double		f = 0.000000000012345678901234567890;

	// ft_printf("%*****5i %1$d", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// printf("%******d %1$d", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// ft_printf("%**5****d %1$d", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	// printf("%5Lf", f/0);
	printf("%.28Lf", f);
	// printf("%5Lf", -LDBL_MAX);

	// ft_printf("%Lf %3$c %2$i", f, 1, '{');
	// for_arg("rtryr", 123.123L, 234.234L, 345.345L, 456.456L);
	return (0);
}