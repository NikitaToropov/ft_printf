
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
		printf("PARAM is '%d'\n", first_arg->parameter);
		printf("FLAGS is '%i'\n", (int)(first_arg->flags));
		printf("WIDTH is '%i' N_ARG_WIDTH is '%i'\n", first_arg->width, first_arg->n_arg_width);
		printf("PRECISS is '%i' N_ARG_PRECISS is '%i'\n", first_arg->precision, first_arg->n_arg_precision);
		printf("LENGTH is '%c'\n", first_arg->length);
		printf("TYPE is '%c'\n", first_arg->type);
		printf("N_ARG is '%i'\n", first_arg->n_arg);
		printf("N_OF_LIST is '%u'\n\n", first_arg->n_of_list);

		first_arg = first_arg->next;
	}
	ft_clear_the_struct(&first_arg);
	return (num_of_chars);
}