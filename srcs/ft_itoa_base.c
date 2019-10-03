#include "ft_printf.h"

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
	unsigned int			modulo;
	char 					l[] = "abcdef";


	if (n == 0)
		return ("0\0");
	len = ft_uns_len(n, base);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		ft_errors(0);
	result[len] = '\0';
	while (n > 0)
	{
		if ((modulo = n % base) > 9)
			result[--len] = l[modulo - 10];
		else
			result[--len] = modulo + '0';
		n /= (long long)base;
	}
	return (result);
}

char	*ft_ITOA_base(unsigned long long n, int base)
{
	char					*result;
	unsigned int			len;
	unsigned int			modulo;
	char 					l[] = "ABCDEF";


	if (n == 0)
		return ("0\0");
	len = ft_uns_len(n, base);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		ft_errors(0);
	result[len] = '\0';
	while (n > 0)
	{
		if ((modulo = n % base) > 9)
			result[--len] = l[modulo - 10];
		else
			result[--len] = modulo + '0';
		n /= (long long)base;
	}
	return (result);
}