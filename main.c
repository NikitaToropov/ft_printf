	#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>


int		main(void)
{	
	long double		f = -255;

	// ft_printf("%Lf %i", f, 123456);
	// ft_printf("%bi, %bLf, %s", 255, f, "str");
	// printf("%p\n", 255);
	// printf("%.10p", 255);
	// ft_printf("%5>i %i\n", 255);

	// ft_printf("%>i %d %c %04$5i\n", 1, 2, 3, 4, 5, 6);
	// printf("%.3p\n", 255);
	ft_printf("%Lf\n", 12345678901234567890e70L);
	printf("\n\n%Lf\n", 12345678901234567890e70L);
	// ft_printf("%p\n", 0);

	return (0);
}
// -0.000000000123456780000000000
// -0.000000000123456780000000000