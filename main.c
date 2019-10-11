// #include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <float.h>

// 1\100 0000 ' 0000 0110 \1011 0010 ' 0010 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000
// 		9			8		   7		   6		   5		   4		   3		   2		   1			0

// int		power_of_two


void	ft_print_bits(void *c, unsigned int len)
{
	unsigned char	scaner;
	unsigned char	*m;

	unsigned int	a = 1;

	// printf("%u\n", len);
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

unsigned long long int		power_of_five(short i)
{
	unsigned long long int		res;

	res = 5;
	while (i > 1)
	{
		res *= 5;
		i--;
	}

	return (res);
}

void	put_chars_to_fractional(short exp, char *fractional, unsigned long long b_fr)
{
	unsigned long long int	num;
	short			a;
	short			b;

	if (!b_fr)
	{
		fractional[0] = '\0';
		return ;
	}
	if (exp < 0)
		exp *= -1;
	else
		exp = 1;
	fractional[0] = '.';
	a = 1;
	// fractional[16382] = '\0';
	while (b_fr)
	{
		// printf("\n\nPOWEEEER %hd\n\n", a);

		fractional[a] = '0';
		fractional[a + 1] = '\0';

		if (a >= exp && (b_fr & 0x8000000000000000))	
		{
			num  = power_of_five(a);

			b = a;
			while (num)
			{
				if ((fractional[b] += (char)(num % 10)) > '9')
				{
					fractional[b] = (fractional[b] - '0') % 10 + '0';				
					num += 10;
				}
				b--;
				num /= 10;
			}
			// printf("\n\nPOWEEEER %llu\n\n", num);
			b_fr = b_fr << 1;
		}
		a++;
	}
}

// void	put_chars_to_integer(short exp, char *integer, usigned long long b_int)
// {
// 	unsigned int	num;

// 	integer[0] = '0';
// 	num = 
// 	while (exp)
// 	{

// 	}
// }

void	make_string(short exp, unsigned long long int b_int, unsigned long long int b_fr)
{
	char		integer[4935];
	char		fractional[16383];

	// put_chars_to_integer(exp, integer, b_int);
	put_chars_to_fractional(exp, fractional, b_fr);
	printf("\n\n\n\n%s\n\n", fractional);
}


void	put_long_double(void *c)
{
	unsigned long long int		bin_integer;
	unsigned long long int		bin_fractional;
	short						exponent;

	exponent = (*((unsigned long long int*)c + 1) & 0x7FFF) - 0x3FFF;
	if (exponent < 0)
	{
		bin_fractional = *(unsigned long long int*)c;
		bin_integer = 0;
	}
	else if (exponent >= 63)
	{
		bin_fractional = 0;
		bin_integer = *(unsigned long long int*)c;
	}
	else
	{
		bin_fractional = *(unsigned long long int*)c << (exponent + 1);
		bin_integer = *(unsigned long long int*)c >> (62 - exponent) << (62 - exponent);
	}
	
	
	ft_print_bits((unsigned long long int*)c, sizeof((unsigned long long int*)c));

	make_string(exponent, bin_integer, bin_fractional);


	write(1, "exponent is:\n" ,13);
	ft_print_bits(&exponent, sizeof(exponent));
	
	write(1, "\n\nbin_integer is:\n" ,18);
	ft_print_bits(&bin_integer, sizeof(bin_integer));

	write(1, "\n\nbin_fractional is:\n" ,21);
	ft_print_bits(&bin_fractional, sizeof(bin_fractional));
}

int		main(void)
{	
	// long double		c = -178.125;
	// long double		c = LDBL_MIN;
	long double		c = 0.0000875;
	// LDBL_MIN  16382  + 1 len 
	// LDBL_MAX 4934 + 1 len
	

	
	// printf("%d\n", printf("%.16382Lf\n", (LDBL_MIN)));
	// printf("%d\n", printf("%Lf\n", (long double)1.5));
	// printf("%Lf\n", LDBL_MIN);

	// printf("%Lf\n", c);
	put_long_double(&c);


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
// 1\100 0000 ' 0000 0110 \1011 0010 ' 0010 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000
// 		9			8		   7		   6		   5		   4		   3		   2		   1			0