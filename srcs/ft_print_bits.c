#include "ft_printf.h"

void	ft_print_bits(void *c, unsigned int len)
{
	unsigned char	l;
	unsigned char	*m;
	unsigned int	a = 1;

	m = (unsigned char*)c;
	while (len)
	{
		l = 128;
		while (l)
		{
			if (*m & l)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			// if (a == || a == || a ==)
			if (l == 16)
				write(1, " ", 1);
			// if (a == || a == || a ==)
			l /= 2;
		}
		len--;
		m++;
		if (len)
			write(1, " ", 1);
	}
}