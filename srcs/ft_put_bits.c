#include "ft_printf.h"

char	*ft_make_string_bin(void *c, int len)
{
	unsigned char	scaner;
	unsigned char	*byte;
	char			*str;
	unsigned int	pos;

	str = (char*)malloc(sizeof(char) * (len * 8 + (len * 2 - 1) + 1));
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
			pos++;
			if (scaner == 16 || (scaner == 1 && byte != (unsigned char*)c))
			{
				str[pos] = ' ';
				pos++;
			}
			scaner /= 2;
		}
		byte--;
	}	
	str[pos] = '\0';
	// printf("%s", str);
	return (str);
}

void	ft_put_bits(void *c, s_args *list)
{
	int		len;

	if (list->type == 'f')
	{
		if (list->length == 'F')
			len = 10;
		else
			len = sizeof(double);
	}
	else
	{
		if (list->length == 'H' || list->type == 'c')
			len = sizeof(char);
		else if (list->length == 'h')
			len = sizeof(short);
		else if (list->length == 'L')
			len = sizeof(long long int);
		else if (list->length == 'l')
			len = sizeof(long int);
		else
			len = sizeof(int);
	}
	list->arg = ft_make_string_bin(c, len);
}