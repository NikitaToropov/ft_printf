#include "ft_printf.h"

void	ft_errors(void)
{
	write(1, "memory is not alocated\n", 23);
	exit(1);
}
