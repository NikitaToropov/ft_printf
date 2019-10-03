#include "ft_printf.h"

char	*ft_utf_8_coder(int sym)
{
	char		*str;
	
	if (sym > 1114111)
		ft_errors(4);
	if (sym >= 0 && sym <= 127) //00000000-0000007F
	{
		if (!(str = (char*)malloc((char) * 2)))
			ft_errors(0);
		str[0] = (char)sym;
		str[1] = '\0';
	}
	else if (sym > 127 && sym <= 2047) //00000080-000007FF
	{
		if (!(str = (char*)malloc((char) * 3)))
			ft_errors(0);
		str[0] = (unsigned char)(((sym >> 6) & 31) | 192);
		str[1] = (unsigned char)((sym & 63) | 128);
		str[2] = '\0';
	}
	else if (sym > 2047 && sym <= 65535) //00000800-0000FFFF
	{
		if (!(str = (char*)malloc((char) * 4)))
			ft_errors(0);
		str[0] = (unsigned char)(((sym >> 12) & 15) | 224);
		str[1] = (unsigned char)(((sym >> 6) & 63) | 128);		
		str[2] = (unsigned char)((sym & 63) | 128);
		str[3] = '\0';
	}
	else //00010000-0010FFFF
	{
		if (!(str = (char*)malloc((char) * 5)))
			ft_errors(0);
		str[0] = (unsigned char)(((sym >> 18) & 7) | 240);
		str[1] = (unsigned char)(((sym >> 12) & 63) | 128);
		str[2] = (unsigned char)(((sym >> 6) & 63) | 128);
		str[3] = (unsigned char)((sym & 63) | 128);
		str[4] ='\0';
	}
	return (str);
}

// void	ft_unicode_char_print(int sym)
// {
// 	unsigned char	octet1;
// 	unsigned char	octet2;
// 	unsigned char	octet3;
// 	unsigned char	octet4;

// 	if (sym > 1114111) 
// 		ft_errors(4);
// 	if (sym >= 0 && sym <= 127) //00000000-0000007F
// 		write(1, &sym, 1);
// 	else if (sym > 127 && sym <= 2047) //00000080-000007FF
// 	{
// 		octet1 = (unsigned char)(((sym >> 6) & 31) | 192);
// 		octet2 = (unsigned char)((sym & 63) | 128);
// 		write(1, &octet1, 1);
// 		write(1, &octet2, 1);
// 	}
// 	else if (sym > 2047 && sym <= 65535) //00000800-0000FFFF
// 	{
// 		octet1 = (unsigned char)(((sym >> 12) & 15) | 224);
// 		octet2 = (unsigned char)(((sym >> 6) & 63) | 128);		
// 		octet3 = (unsigned char)((sym & 63) | 128);
// 		write(1, &octet1, 1);
// 		write(1, &octet2, 1);
// 		write(1, &octet3, 1);
// 	}
// 	else //00010000-0010FFFF
// 	{
// 		octet1 = (unsigned char)(((sym >> 18) & 7) | 240);
// 		octet2 = (unsigned char)(((sym >> 12) & 63) | 128);
// 		octet3 = (unsigned char)(((sym >> 6) & 63) | 128);
// 		octet4 = (unsigned char)((sym & 63) | 128);
// 		write(1, &octet1, 1);
// 		write(1, &octet2, 1);
// 		write(1, &octet3, 1);
// 		write(1, &octet4, 1);
// 	}
// }