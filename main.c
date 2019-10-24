// #include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <float.h>

void	ft_make_str(int int_len, int frac_len, long double ld)
{
	long double			tmp_ld;
	unsigned int		sim;
	char				*str;
	unsigned int		len;
	unsigned int		counter;

	tmp_ld = ld;
	if (ld < 0)
	{
		tmp_ld *= -1;
		int_len++;
	}
	if (!frac_len)
		len = (unsigned long long int)int_len;
	else
		len = (unsigned long long int)(frac_len + int_len + 1);
	str = malloc(sizeof(char) * (len + 1));
	str[int_len] = '.';
	str[len] = '\0';
	str[0] = '0';
	if (ld < 0)
	{
		str[0] = '-';
		str[1] = '0';
	}
	counter = int_len - 1;
	while (tmp_ld >= 1 && counter >= 0)
	{
		sim = (unsigned long long int)tmp_ld % 10;
		str[counter] = sim + '0';
		tmp_ld /= 10;
		counter--;
	}
	counter = int_len + 1;
	tmp_ld = ld;
	if (tmp_ld < 0)
		tmp_ld *= -1;
	while (counter < len)
	{
		tmp_ld *= 10;
		sim = (unsigned long long int)tmp_ld % 10;
		str[counter] = sim + '0';

		counter++;
	}
	printf("%s\n", str);
}

void	ft_parse_floating_arg(long double argument)
{
	int	integer_len;
	int	fractional_len;
	long double 	tmp;

	tmp = argument;
	if (tmp == 0)
	{
		printf("0");
		return ;
	}
	
	integer_len = 1;
	if (tmp < 0)
		tmp *= -1;
	while ((tmp /= 10) >= 1)
		integer_len++;
	
	tmp = argument;
	fractional_len = 0;
	if (tmp < 0)
		tmp *= -1;
	fractional_len = 0;
	if (integer_len == 1 && tmp < 1)
	{
		fractional_len = 0;
		while ((tmp *= 10) < 1)
			fractional_len++;
		fractional_len +=18;
	}
	else
	{
		if (integer_len >= 18)
			fractional_len = 0;
		else
			fractional_len = 18 - integer_len;
	}
	ft_make_str(integer_len, fractional_len, argument);
}

int		main(void)
{	
	// long double		c = 0l;
	long double		c = -1234567890123456789001.1L;
	// long double		c = -1234567890123456789012.12567l;		//dnt frgt

	// printf("%d\n", LDBL_DECIMAL_DIG);
	// printf("%d\n", LDBL_DECIMAL_DIG)
	printf("%.50Lf\n", c);
	ft_parse_floating_arg(c);
	return (0);
}