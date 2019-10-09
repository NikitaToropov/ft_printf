// #include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	put_long_double(void *c)
{
	unsigned char	*m;

	m =
}
// {
// 	unsigned char	scaner;
// 	unsigned char	*m;
// 	unsigned int	a = 1;

// 	printf("%u\n", len);
// 	m = (unsigned char*)c + len - 1;
// 	while (m >= (unsigned char*)c)
// 	{
// 		scaner = 128;
// 		while (scaner)
// 		{
// 			if (*m & scaner)
// 				write(1, "1", 1);
// 			else
// 				write(1, "0", 1);
// 			// if (a == || a == || a ==)
// 			if (scaner == 16)
// 				write(1, " ", 1);
// 			// if (a == || a == || a ==)
// 			scaner /= 2;
// 		}
// 		if (m != (unsigned char*)c)
// 			write(1, " ", 1);
// 		m--;
// 	}	
// }

void	ft_print_bits(void *c, unsigned int len)
{
	unsigned char	scaner;
	unsigned char	*m;
	unsigned int	a = 1;

	printf("%u\n", len);
	m = (unsigned char*)c + 9;
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

int		main(void)
{	
	// char 			*str;
	// long long int	i = 1234567876;
	// float			l = 3.4 * 10 ^ 38;
	long double		c = -178.125;
	// double		c = -178.125;
	// int		c = 4991;

	printf("%Lf\n", c);
	ft_print_bits(&c, sizeof(c));
	// c = c<<1>>24;
	// ft_print_bits(&c, sizeof(c));

	// printf("%zu", sizeof(long double));

	return (0);
}
// float:
// 1100  0011  0011 0010 0010 0000 0000 0000
// 1\100 0011 0\011 0010 0010 0000 0000 0000
// 100 0011 0 - 0111 1111 = 111 == 7 (M << 1 >>24)

// double:
// 1100 0000 0110 0110 0100 0100 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
// 1\100 0000 0110 \0110 0100 0100 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000

// long double: ?? (sizof = 16 but real size 20)
// 1100 0000 0000 0110 1011 0010 0010 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
// 1\100 0000 0000 0110 \1011 0010 0010 0000 ' 0000 0000 0000 0000 ' 0000 0000 0000 0000 ' 0000 0000 0000 0000