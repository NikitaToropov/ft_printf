#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <float.h>

int		main(void)
{	
	// long double		c = 0l;
	// long double		c = -1234567890123001.12345e20L;
	double		a = 123.123;
	double		b = 123.123;
	double		c = 123.123;
	double		d = 123.123;
	double		e = 123.123;
	double		f = 123.123;

	// long double		c = -1234567890123456789012.12567l;		//dnt frgt

	// printf("%d\n", LDBL_DECIMAL_DIG);
	// printf("%d\n", LDBL_DECIMAL_DIG)
	// printf("%.50Lf\n", c);
	// ft_parse_floating_arg(c);

	// ft_printf("%i", b);
	ft_printf("%f", a, b, c, d, e, f);
	return (0);
}