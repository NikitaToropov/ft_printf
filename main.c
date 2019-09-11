#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	ft_put_letter(unsigned int remainder, unsigned int base)
{
	char 	l[] = "aabcdef";

	return (l[base]);
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
	char					c;

	len = ft_uns_n_len(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = '0';
	while (n > 0)
	{
		if ((remainder = n % base) > 9)
			c = ft_put_letter(remainder, base);
		else
			c = remainder + '0';
		str[--len] = c;
		n /= base;
	}
	return (str);
}


int		main(void)
{	
	int	i = 16;
	// int	i = 1234578901238675435;
	long long	b;

 	printf("it's real %x\n", i);
	// b = (short)i;
 	printf("it's itoa %s\n", ft_uns_itoa_base(b, 16));
	return (0);
}