#include <float.h>

int		main(void)
{
	double		a = 255.000000;
	long double		d = 255.000000;
	// int				i = 123;

	// ft_printf("%s\n%d\n%p\n%%", "yoyoyoyoyoy", i, &i);
	ft_printf("%Lbf\n", d);
	ft_printf("%bf\n", a);
	ft_printf("%c\n", 128125);
	// ft_printf("%Lf\n", LDBL_MAX);
	// printf("%Lf\n", LDBL_MAX);
	ft_printf("%'c%1$*2$'c%1$*2$'c%1$*2$'c%1$*2$'c", 128125, 6);
	return (0);
}