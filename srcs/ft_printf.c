
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	a_list		*first_arg;
	int			num_of_chars;

	num_of_chars = 0;
	// ft_testing(format);
	// return (num_of_symbls);
	first_arg = ft_make_struct(format);
	printf("yo\n");
	while (first_arg)
	{
		write(1, &(first_arg->flags), 1);
		first_arg = first_arg->next;
	}
	return (num_of_chars);
}