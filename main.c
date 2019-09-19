#include "ft_printf.h"

int		main(void)
{	
	int		a = 1;
	int		b = 2;
	int		c = 3;
	char	v = 126;

	ft_printf("%ll#l2$d %llll04&% %12$  3$34$hhhf %hhh   hs");
	// printf("%c\n", '\'');
	return (0);
}