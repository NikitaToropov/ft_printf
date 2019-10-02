#include "ft_printf.h"
// #include <stdio.h>

int		main(void)
{	
	// long			a = -1;
	// int			b = -2;
	// float		c = 4.0000;
	// char		*v = "126";
	// long double	d = 9223372036854775807.0;

	
	ft_printf("%i %1$hi %1$hhi %1$li %1$lli %1$Li", 4294967295, 2, 3, 4);
	//    printf("%i %1$hi %1$hhi %1$li %1$lli %1$Li", 4294967295, 2, 3, 4);

	// printf("%Li", 4294967295);

	// printf("%1$f %1$i\n", 1, 2, 3.4);
	// printf("%1$i %1$f", 1, 2, 3.4);

	// printf("%p\n", v);
	// printf("%x\n", (unsigned int)v);   //what u wanr to do with 'p'
	return (0);
}