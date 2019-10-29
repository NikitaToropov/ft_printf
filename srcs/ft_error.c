#include "ft_printf.h"

void	ft_error(int code)
{
	if (code == 1)
		write(1, "memory is not alocated\n", 23);
	if (code == 2)
		write(1, "some arguments were skipped\n", 28);
	exit(1);
}
