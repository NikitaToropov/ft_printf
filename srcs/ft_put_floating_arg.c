#include "ft_printf.h"

int		ft_count_int_length(long double uns_arg)
{
	int		int_len;

	int_len = 1;
	while ((uns_arg /= 10) >= 1)
		int_len++;
	return (int_len);
}

int		ft_count_frac_len(int sign_dig, int int_len, long double uns_arg)
{
	int		frac_len;

	if (int_len == 1 && uns_arg < 1)
	{
		frac_len = 0;
		while ((uns_arg *= 10) < 1)
			frac_len++;
		frac_len += sign_dig;
	}
	else
	{
		if (int_len >= sign_dig)
			frac_len = 0;
		else
			frac_len = sign_dig - int_len;
	}
	if (frac_len < 6)
		frac_len = 6;
	return (frac_len);
}

void	ft_fill_by_int(char *str, int sign_dig, int rev_counter, long double ld)
{
	str[rev_counter] = '.';
	rev_counter--;
	while (rev_counter >= 0)
	{
		if (rev_counter >= sign_dig)
			str[rev_counter] = '0';
		else
			str[rev_counter] = ((unsigned long long int)ld % 10) + '0';
		ld /= 10;
		rev_counter--;
	}
}

void	ft_fill_by_frac(char *str, int frac_len, long double uns_ld)
{
	int		counter;

	counter = 0;
	while (counter < frac_len)
	{
		uns_ld *= 10;
		str[counter] = ((unsigned long long int)uns_ld % 10) + '0';
		counter++;
	}
}

char	*ft_ld_string(int sign_dig, int int_len, int frac_len, long double ld)
{
	char				*str;
	int					len;

	len = frac_len + int_len + 1;
	if (ld < 0)
		len++;

	if (!(str = malloc(sizeof(char) * (len + 1))))
		ft_error(1);
	str[len] = '\0';

	if (ld < 0)
	{
		str[0] = '-';
		ft_fill_by_int(&str[1], sign_dig, int_len, ld * (-1));
		ft_fill_by_frac(&str[int_len + 2], frac_len, ld * (-1));
	}
	else
	{
		ft_fill_by_int(str, sign_dig, int_len, ld);
		ft_fill_by_frac(&str[int_len + 1], frac_len, ld);
	}
	
	return (str);
}

void	ft_put_floating_arg(s_args *list, long double argument)
{
	int				int_len;
	int				frac_len;
	long double 	tmp;
	int				sign_dig; //significant digits


	if (!argument)
		list->arg = "0";
	else if (argument != argument)
		list->arg = "nan";
	else if (argument == (argument + argument) && argument > 0)
		list->arg = "inf";
	else if (argument == (argument + argument) && argument < 0)
		list->arg = "-inf";
	else
	{
		tmp = argument;
		if (tmp < 0)
			tmp *= -1;
		int_len = 1;
		if (list->length == 'F')
			sign_dig = LDBL_DIG;
		else
			sign_dig = DBL_DIG;
		int_len = ft_count_int_length(tmp);
		frac_len = ft_count_frac_len(sign_dig, int_len, tmp);
		list->arg = ft_ld_string(sign_dig, int_len, frac_len, argument);
	}
}