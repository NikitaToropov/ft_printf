
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	a_list		*first_arg;
	int			num_of_chars;

	num_of_chars = 0;
	first_arg = ft_make_struct(format);
	while (first_arg)
	{
		// write(1, &(first_arg->type), 1);
		printf("TYPE is '%c'\n", first_arg->type);
		printf("PARAM is '%d'\n\n", first_arg->parameter);
		first_arg = first_arg->next;
	}
	ft_clear_the_struct(&first_arg);
	return (num_of_chars);
}