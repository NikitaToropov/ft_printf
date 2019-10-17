#include "ft_printf.h"

char	*ft_put_bits(void *c, unsigned int len)
{
	unsigned char	scaner;
	unsigned char	*byte;
	char			*str;
	unsigned int	pos;

	str = (char*)malloc(sizeof(char) * ((len / 4 - 1) + len + 1));
	byte = (unsigned char*)c + len - 1;
	pos = 0;
	while (byte >= (unsigned char*)c)
	{
		scaner = 128;
		while (scaner)
		{
			if (*byte & scaner)
				str[pos] = '1';
			else
				str[pos] = '0';
			pos += 1;
			if (scaner == 16 || (scaner == 1 && byte != (unsigned char*)c))
			{
				str[pos] = ' ';
				pos += 1;
			}
			scaner /= 2;
		}
		byte--;
	}	
	str[pos] = '\0';
	// printf("%s", str);
	return (str);
}