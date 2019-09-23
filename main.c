#include "ft_printf.h"

int		main(void)
{	
	int		a = 1;
	int		b = 2;
	int		c = 4;
	char	*v = "126";

	ft_printf("%4% %4.1234$d %123.4 .*llld");
	// printf("%7 0<s % ses", "123", "456");
	// printf("%12\n");
	return (0);
}



// PARAM is '0'$
// FLAGS is '0'$
// WIDTH is '-1' N_ARG_WIDTH is '0'$
// PRECISS is '-1' N_ARG_PRECISS is '0'$
// LENGTH is '^@'$
// TYPE is '%'$
// $
// PARAM is '0'$
// FLAGS is '0'$
// WIDTH is '4' N_ARG_WIDTH is '0'$
// PRECISS is '1234' N_ARG_PRECISS is '0'$
// LENGTH is '^@'$
// TYPE is '$'$
// $
// PARAM is '0'$
// FLAGS is '8'$
// WIDTH is '123' N_ARG_WIDTH is '0'$
// PRECISS is '-1' N_ARG_PRECISS is '1'$
// LENGTH is 'l'$
// TYPE is 'd'$
// $