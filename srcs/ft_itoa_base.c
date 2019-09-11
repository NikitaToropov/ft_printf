#include <unistd.h>
#include <stdlib.h>

unsigned int	ft_uns_n_len(unsigned long long nb, int base)
{
	unsigned int	ln;

	ln = 1;
    
    if (base == 17)
        base = 16;    
	while (nb / base != 0)
	{
		ln++;
		nb /= base;
	}
	return (ln);
}

char	*ft_uns_itoa_base(unsigned long long n, int base)
{
	char					*str;
	unsigned int			len;

	len = ft_n_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = '0';

	if (base == 17)
        base = 16;

	while (n > 0)
	{
		str[--len] = n % base + '0';
		n /= base;
	}
	return (str);
}
