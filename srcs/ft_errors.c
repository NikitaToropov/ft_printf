#include "ft_printf.h"

void	ft_errors(int code)
{
	if (!code)
		write(1, "memory is not alocated\n", 23);
	else if (code == 1)
		write(1, "error\n", 6);
	else if (code == 2)
		write(1, "usage: reals and integers with parameter \'n$\'\n", 46);
	else if (code == 3)
		write(1, "usage: real numbers various length with parameter \'n$\'\n", 55);
	else if (code == 4)
		write(1, "usage: Unicode character set incorrectly\n", 44);
	exit(1);
}
