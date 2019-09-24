#include "ft_printf.h"

int		main(void)
{	
	int		a = 1;
	int		b = 2;
	int		c = 4;
	char	*v = "126";

	ft_printf("%5$*s %2$.*d %123.4 .*llld");
	// printf("	\n");
	// printf("%4	s\n", "1234");
	return (0);
}


	// PARAM is '5'
	// FLAGS is '8'
	// WIDTH is '1' N_ARG_WIDTH is '0'
	// PRECISS is '4' N_ARG_PRECISS is '0'
	// LENGTH is ''
	// TYPE is 's'
	// N_ARG is '0'
	// N_OF_LIST is '1'

	// PARAM is '0'
	// FLAGS is '8'
	// WIDTH is '-1' N_ARG_WIDTH is '0'
	// PRECISS is '-1' N_ARG_PRECISS is '0'
	// LENGTH is ''
	// TYPE is '%'
	// N_ARG is '0'
	// N_OF_LIST is '2'

	// PARAM is '0'
	// FLAGS is '8'
	// WIDTH is '123' N_ARG_WIDTH is '0'
	// PRECISS is '-1' N_ARG_PRECISS is '1'
	// LENGTH is 'l'
	// TYPE is 'd'
	// N_ARG is '0'
	// N_OF_LIST is '3'