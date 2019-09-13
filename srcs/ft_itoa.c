#include "ft_printf.h"

unsigned int	ft_len(long long nb)
{
	unsigned int	len;

	len = 1;
	if (nb < 0)
		len++;
	while ((nb /= 10))
		len++;
	return (len);
}

char	*ft_itoa(long long n)
{
	char					*str;
	unsigned long long		nb;
	unsigned int			len;

	nb = (unsigned long long)(n);
	if (n < 0)
		nb = (unsigned long long)(n * -1);
	len = ft_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (nb)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}


// получаем аргументы как:
// va_argv(ap, long long)
// внутри вызова итоа кастим в соответствующий тип: hhd ft_itoa((char)i)