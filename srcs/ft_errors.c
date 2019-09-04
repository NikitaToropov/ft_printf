#include "ft_printf.h"

void	ft_error(int code)
{
	if (code == 1)
		write(1, "error\n", 6);
	else
		write(1, "memory is not alocated\n", 23);
	exit(1);
}
