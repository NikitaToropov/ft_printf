#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{	
	char 			*str;
	long long int	i = 1234567876;

	str = "allright dude?";
	printf("%2$p   %1$p", str, i);
	ft_printf("%2$p   %1$p", str, i);
	// ft_printf("%p", str);
	return (0);
}
//499602c4