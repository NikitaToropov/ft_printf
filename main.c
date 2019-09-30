#include "ft_printf.h"
// #include <stdio.h>

int		main(void)
{	
	// long			a = -1;
	// int			b = -2;
	// float		c = 4.0000;
	// char		*v = "126";
	long double	d = 9223372036854775807.0;

	// ft_printf("%2$1*.*9*i %1*.*9*i %123 1$0#-s");
	// printf("%2$*4$.*3$14i %*4$.*3$i\n", 1, 2, 3, 4, 5);
	
	// ft_printf("%2$*i");
	// ft_printf("%2$*4$.*3$14i %*4$.*3$i");

	// printf("%f\n", d);
		// write(1, "usage: wrong use reals and integers with parameter \'n$\'\n", 56);
	write(1, "usage: reals and integers with parameter \'n$\'\n", 46);
	write(1, "usage: real numbers various length with parameter \'n$\'\n", 55);
	return (0);
}