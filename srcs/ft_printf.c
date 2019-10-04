
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	a_list		*first_arg;
	int			num_of_chars;

	num_of_chars = 0;
	first_arg = ft_make_struct(format);
	while (first_arg)
	{
		printf("\n\"parameter\"         is '%d'\n", first_arg->parameter);
		printf("\"n_arg_width\"       is '%d'\n", first_arg->n_arg_width);
		printf("\"n_arg_precision\"   is '%d'\n", first_arg->n_arg_precision);
		printf("\"n_arg\"             is '%d'\n\n", first_arg->n_arg);

		printf("\"width\"             is '%d'\n", first_arg->width);
		printf("\"precision\"         is '%d'\n", first_arg->precision);
		printf("\"arg\"               is '%s'\n\n", first_arg->arg);
		
		printf("\"flags\"             is '%i'\n", first_arg->flags);
		printf("\"length\"            is '%c'\n", first_arg->length);
		printf("\"type\"              is '%c'\n", first_arg->type);
		printf("------------------------------------\n\n");


		first_arg = first_arg->next;
	}
	ft_clear_the_struct(&first_arg);
	return (num_of_chars);
}