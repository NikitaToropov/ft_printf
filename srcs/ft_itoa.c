#include "ft_printf.h"

unsigned int	ft_len(long long number)
{
	unsigned int	len;

	len = 1;
	if (number < 0)
		len++;
	while (number /= 10)
		len++;
	return (len);
}

char	*ft_itoa(long long n)
{
	char					*result;
	unsigned long long		number;
	unsigned int			len;

	if (n == 0)
		return ("0\0");
	number = (unsigned long long)(n);
	if (n < 0)
		number = (unsigned long long)(n * -1);
	len = ft_len(n);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		ft_errors();
	result[len--] = '\0';
	if (n < 0)
		result[0] = '-';
	while (number)
	{
		result[len--] = number % 10 + '0';
		number /= 10;
	}
	return (result);
}


// получаем аргументы как:
// va_argv(ap, long long)
// внутри вызова итоа кастим в соответствующий тип: hhd ft_itoa((char)i)