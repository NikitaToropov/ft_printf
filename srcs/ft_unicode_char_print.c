#include "ft_printf.h"

void	ft_unicode_char_print(int sym)
{
	unsigned char	octet1;
	unsigned char	octet2;
	unsigned char	octet3;
	unsigned char	octet4;

	if (sym > 1114111) 
		ft_errors(4);
	octet1 = (unsigned char)240;
	octet2 = (unsigned char)(((sym >> 12) & 31) | 128);
	octet3 = (unsigned char)(((sym >> 6) & 63) | 192);
	octet4 = (unsigned char)((sym & 63) | 128);
	if (sym >= 0 && sym <= 127) //00000000-0000007F
		write(1, &octet4, 1);
	else if (sym > 127 && sym <= 2047) //00000080-000007FF
	{
		write(1, &octet3, 1);
		write(1, &octet4, 1);
	}
	else if (sym > 2047 && sym <= 65535) //00000800-0000FFFF
	{
		write(1, &octet2, 1);
		write(1, &octet3, 1);
		write(1, &octet4, 1);
	}
	else //00010000-0010FFFF
	{
		write(1, &octet1, 1);
		write(1, &octet2, 1);
		write(1, &octet3, 1);
		write(1, &octet4, 1);
	}
}