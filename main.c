#include "ft_printf.h"

int		main(void)
{	
	int		a = 1;
	int		b = 2;
	int		c = 4;
	char	*v = "126";

	ft_printf("%>12$#+- 22$0d");
	// printf("%>12$#+- 22$0d", 1234567);
	return (0);
}
