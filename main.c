	// #include "ft_printf.h"
	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <float.h>

	// 1\100 0000 ' 0000 0110 \1011 0010 ' 0010 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000 ' 0000 0000
	// 		9			8		   7		   6		   5		   4		   3		   2		   1			0

	// int		power_of_two


	char	*ft_print_bits(void *c, unsigned int len)
	{
		unsigned char	scaner;
		unsigned char	*byte;
		char			*str;
		unsigned int	pos;

		unsigned int	a = 1;

		str = (char*)malloc(sizeof(char) * ((len / 4 - 1) + len + 1));
		byte = (unsigned char*)c + len - 1;
		pos = 0;
		while (byte >= (unsigned char*)c)
		{
			scaner = 128;
			while (scaner)
			{
				if (*byte & scaner)
					str[pos] = '1';
				else
					str[pos] = '0';
				pos += 1;
				if (scaner == 16 || (scaner == 1 && byte != (unsigned char*)c))
				{
					str[pos] = ' ';
					pos += 1;
				}
				scaner /= 2;
			}
			byte--;
		}	
		str[pos] = '\0';
		return (str);
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

		// printf("bin_fractional is\n%s\n\n", ft_print_bits(&b_fr, sizeof(b_fr)));

		if (!b_fr)
		{
			printf("yoyoyoyoyoy");
			fractional[0] = '\0';
			return ;
		}
		if (exp < 0)
			exp *= -1;
		else
			exp = 1;
		fractional[0] = '0';
		a = 1;
		while (a < exp)
		{
			fractional[a] = '0';
			a++;
		}
		// printf("%hi\n\n", exp);
		while (b_fr)
		{
			fractional[a] = '0';
			fractional[a + 1] = '\0';
			// printf("%s\n", fractional);
			if (b_fr & 0x8000000000000000)
			{
				num  = power_of_five(a); // реже
				b = a;
				while (num)
				{
					fractional[b] += num % 10;
					if (fractional[b] > '9')
					{
						fractional[b] -= 10;		
						num += 10;
					}
					b--;
					num /= 10;
				}
			}
			b_fr = b_fr << 1;
			a++;
		}
		printf("%hi\n", a);
	}

	void	make_string(short exp, unsigned long long int b_int, unsigned long long int b_fr)
	{
		char		integer[4936]; //+ 1 byte for arithmetics operations
		char		fractional[16383];

		put_chars_to_fractional(exp, fractional, b_fr);
		printf("%s\n\n", fractional);	
	}


	void	put_long_double(void *c)
	{
		unsigned long long int		bin_integer;
		unsigned long long int		bin_fractional;
		short						exponent;

		exponent = (*((unsigned long long int*)c + 1) & 0x7FFF) - 0x3FFF;
		// exponent = (*((unsigned long long int*)c + 1) & 0x7FFF);
		printf("exponent is\n%s\n%hi\n", ft_print_bits(&exponent, sizeof(exponent)), exponent);
		
		// if (exponent == 0x3FFF)
		// 	exponent = 0;
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
		make_string(exponent, bin_integer, bin_fractional);
		
		
		
		// printf("bin_integer is\n%s\n\n", ft_print_bits(&bin_integer, sizeof(bin_integer)));
		// printf("%hi\n\n", exponent);
		// printf("bin_fractional is\n%s\n\n", ft_print_bits(&bin_fractional, sizeof(bin_fractional)));
	}

	int		main(void)
	{	
		// long double		c = -178.125;
		// long double		c = -0;
		// long double		c = LDBL_MIN;
		// long double		c = 0;
		long double		c = 0.0000875;
		// LDBL_MIN  16382  + 1 len 
		// LDBL_MAX 4934 + 1 len

		// printf("%s\n\n", ft_print_bits(&c, sizeof(c)));
		put_long_double(&c);
		
		
		// printf("%i\n%i", LDBL_MIN_10_EXP, LDBL_MAX_EXP);
		// printf("%.100Lf\n", c); //SO IMPORTANT MAAAAN!!!!!!!!!!!!!!!!!!!!!!!!11111
		return (0);
	}
