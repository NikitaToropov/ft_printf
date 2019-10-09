#include "ft_printf.h"

void	ft_print_bits(void *c, unsigned int len)
{
	unsigned char	scaner;
	unsigned char	*m;
	unsigned int	a = 1;

	printf("%u\n", len);
	m = (unsigned char*)c + len - 1;
	while (m >= (unsigned char*)c)
	{
		scaner = 128;
		while (scaner)
		{
			if (*m & scaner)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			// if (a == || a == || a ==)
			if (scaner == 16)
				write(1, " ", 1);
			// if (a == || a == || a ==)
			scaner /= 2;
		}
		if (m != (unsigned char*)c)
			write(1, " ", 1);
		m--;
	}	
}