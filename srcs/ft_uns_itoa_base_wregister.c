#include "ft_printf.h"

char	ft_put_letter(unsigned int remainder)
{
	char 	l[] = "abcdef";

	return (l[remainder - 10]);

}

unsigned int	ft_uns_len(unsigned long long nb, int base)
{
	unsigned int	ln;
	
	ln = 1;
    while (nb /=  base)
		ln++;
	return (ln);
}

char	*ft_itoa_base(unsigned long long n, int base)
{
	char					*result;
	unsigned int			len;
	unsigned int			remainder;

	if (n == 0)
		return ("0\0");
	len = ft_uns_len(n, base);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		ft_errors(0);
	result[len] = '\0';
	while (n > 0)
	{
		if ((remainder = n % base) > 9)
			result[--len] = ft_put_letter(remainder, X);
		else
			result[--len] = remainder + '0';
		n /= (long long)base;
	}
	return (result);
}


char	*ft_itoa_base_uns(unsigned long long n, a_list list)
{
	if (list->type == 'u')
	{
		if (list->length == 'l')
			list->arg = ft_itoa((long int)arg);
		else if (list->length == 'L')
			list->arg = ft_itoa(arg);
		else if (list->length == 'h')
			list->arg = ft_itoa((short)arg);
		else if (list->length == 'H')
			list->arg = ft_itoa((char)arg);
		else
			list->arg = ft_itoa((int)arg);
	}
}

// получаем аргументы как:
// va_argv(ap, unsigned long long)
// внутри вызова итоа кастим в соответствующий тип