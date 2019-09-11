#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	ft_put_letter(unsigned int remainder)
{
	char 	l[] = "abcdef";

	return (l[remainder - 10]);
}

unsigned int	ft_uns_n_len(unsigned long long nb, int base)
{
	unsigned int	ln;
	
	ln = 1;
    while (nb / base != 0)
	{
		ln++;
		nb /= base;
	}
	return (ln);
}

char	*ft_uns_itoa_base(unsigned long long n, unsigned int base)
{
	char					*str;
	unsigned int			len;
	unsigned int			remainder;

	len = ft_uns_n_len(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = '0';
	while (n > 0)
	{
		if ((remainder = n % base) > 9)
			str[--len] = ft_put_letter(remainder);
		else
			str[--len] = remainder + '0';
		n /= base;
	}
	return (str);
}


int		main(void)
{	
	unsigned long long	i = -429557772956666;
	// int	i = 1234578901238675435;
	unsigned long long	b;

 	printf("it's real %u\n", i);
	b = i;
 	printf("it's itoa %s\n", ft_uns_itoa_base(b, 10));
	return (0);
}