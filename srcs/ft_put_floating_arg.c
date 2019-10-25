#include "ft_printf.h"

char	*ft_str_frm_float(int int_len, int frac_len, int n_dig, long double ld)
{
	long double			tmp_ld;
	int					sim;
	char				*str;
	int					len;
	int					counter;

	tmp_ld = ld;
	if (ld < 0)
	{
		tmp_ld *= -1;
		int_len++;
	}

	if (!frac_len)
		len = int_len;
	else
		len = frac_len + int_len + 1;
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
		if (counter > n_dig)
			str[counter] = '0';
		else
		{
			sim = (unsigned long long int)tmp_ld % 10;
			str[counter] = sim + '0';
		}
		tmp_ld /= 10;
		counter--;

	}
// printf("yoyoyoyyoy %s\n", str);
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
	return (str);
}

char	*ft_put_long_double_arg(s_args *list, long double argument)
{
	int				integer_len;
	int				fractional_len;
	int				const_dig;
	long double 	tmp;

	if (argument == 0)
		return ("0\0");

	if (list->length == 'D')
		const_dig = 18;
	else
		const_dig = 15;
	
	tmp = argument;
	integer_len = 1;
	if (tmp < 0)
		tmp *= -1;
	while ((tmp /= 10) >= 1)
		integer_len++;
	fractional_len = 0;
	tmp = argument;
	if (tmp < 0)
		tmp *= -1;
	fractional_len = 0;
	if (integer_len == 1 && tmp < 1)
	{
		fractional_len = 1;
		while ((tmp *= 10) < 1)
			fractional_len++;
		fractional_len += const_dig;
	}
	else
	{
		if (integer_len >= const_dig)
			fractional_len = 0;
		else
			fractional_len = const_dig - integer_len;
	}
	return (ft_str_frm_float(integer_len, fractional_len, const_dig, argument));
}

void	ft_put_floating_arg(s_args *list, long double argument)
{
	double		double_argument;

	// printf("yoyoyoyyoy     %Lf\n\n", argument);

	double_argument = (double)argument;
	if (list->flags & 64 && list->length == 'F')
		list->arg = ft_put_bits(&argument, sizeof(long double));
	else if (list->flags & 64 && list->length != 'F')
		list->arg = ft_put_bits(&double_argument, sizeof(double));
	else
		list->arg = ft_put_long_double_arg(list, argument);
}