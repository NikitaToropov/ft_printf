#include "ft_printf.h"

char	ft_put_letter(unsigned int remainder, int X)
{
	char 	l[] = "abcdef";
	char 	L[] = "ABCDEF";

	if (X)
		return (L[remainder - 10]);
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

char	*ft_uns_itoa_base_wregister(unsigned long long n, unsigned int base, int X)
{
	char					*result;
	unsigned int			len;
	unsigned int			remainder;

	if (n == 0)
		return ("0\0");
	len = ft_uns_len(n, base);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	while (n > 0)
	{
		if ((remainder = n % base) > 9)
			result[--len] = ft_put_letter(remainder, X);
		else
			result[--len] = remainder + '0';
		n /= base;
	}
	return (result);
}

// получаем аргументы как:
// va_argv(ap, unsigned long long)
// внутри вызова итоа кастим в соответствующий тип