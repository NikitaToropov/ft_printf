	#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>


int		main(void)
{	
	// ft_printf("%.0f\n", -0.0000009876543210123456789);
	// ft_printf("%Lf\n", -1.23456789012345678901234567890e50L);
	// ft_printf("%Lf\n", LDBL_MAX);
	// ft_printf("%10>d", 15);
	// printf("%d|%i|%*$i|%i", 10, 2, 3, 4, 5);
	ft_printf("%d %i %*1$i %i", 10, 2, 3, 4);
	// printf("%Lf\n", -1.23456789012345678901234567890e50L);

	return (0);
}