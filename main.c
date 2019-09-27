#include "ft_printf.h"
// #include <stdio.h>

int		main(void)
{	
	long			a = -1;
	int			b = -2;
	float		c = 4.0000;
	char		*v = "126";

	// printf("%i, %1$hhi", -1);
	// b = 
	// printf("%s\n", ft_itoa(b));
	// printf("%lli", b);
	// ft_printf("%2$*3$d");
	
	
	ft_printf("%2$1*.*9*i %1*.*9*i");
	// printf("%2$1*.*9*i", 1, 2, 3, 4, 5);

	// printf("%2$.4$d\n", 1, 2, 3, 4, 5);
	
	// printf("%1$f %1$i\n", 1, 2, 3.4, 5);
	// printf("%1$f %i\n", 1, 2, 3.4, 5);
	// printf("%i %1$f", 1, 2, 3.4, 5);


	// printf("%*.*% %i", 2, 3, 4);	
	// printf("%f %1$d", 1, 3.5, 2);
	// printf("%4	s\n", "1234");
	// if (a == (float)(a + 0.1))
	// 	printf("INT\n");
	// else
	// 	printf("float\n");
	// a = a + 0.5;
	// printf("this is our NUM: '%d'", b);
	// printf("this is our NUM: '%i'", c);
	return (0);
}