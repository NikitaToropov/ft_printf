#include "ft_printf.h"

int		main(void)
{	
	int			i = 6;
	int 		a = 12;
	
 	// printf("%i  %f\n", i, a);
 	// printf("%i\n", a, i);
 	printf("%.15p", &i, a);
	// printf("our itoa %s", ft_uns_itoa_base_wregister(i, 16, 0));

	return (0);
}