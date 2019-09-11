#include <unistd.h>
#include <stdlib.h>

unsigned int	ft_n_len(long long nb)
{
	unsigned int	ln;

	ln = 1;
	if (nb < 0)
		ln++;
	while (nb / 10 != 0)
	{
		ln++;
		nb /= 10;
	}
	return (ln);
}

char	*ft_itoa(long long n)
{
	char					*str;
	unsigned long long		nb;
	unsigned int			len;

	if (n < 0)
		nb = (unsigned long long)(n * -1);
	else
		nb = (unsigned long long)(n);
	len = ft_n_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (nb > 0)
	{
		str[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

// перед тем как пихать в итоа касти таким образом:

// FOR "lld/lli"
	// int	i = -12345678901238675435;
	// long long	b;
	
	// b = (long long)(i) & 4294967295;
	// ft_itoa(b)

// FOR "ld/li"
	// int	i = -12345678901238675435;
	// long long	b;

	// b = (long)(i) & 4294967295;
 	// ft_itoa(b);

// FOR "hhd/hhi"
	// b = (char)i;

// FOR "hd/hi"
	// b = (short)i;