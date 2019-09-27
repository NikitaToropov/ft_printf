#include "ft_printf.h"

int		find_latest_arg(a_list *list)
{
	int		biggest;

	biggest = 0;
	while (list)
	{
		if (biggest < list->n_arg_width)
			biggest = list->n_arg_width;
		if (biggest < list->n_arg_precision)
			biggest = list->n_arg_precision;
		if (biggest < list->n_arg)
			biggest = list->n_arg;
		list = list->next;
	}
	return (biggest);
}

void    put_the_arg(a_list *first_list, va_list ap, int number)
{
    a_list      *tmp_list;
    unsigned long long i;
    
    
    
    
    number = 0;




    tmp_list = first_list;
    i = va_arg(ap, long long int);
    // printf("%llf\n", i);
    // printf("%i\n", (int)i);
    // printf("%f\n", );
    // printf("%i\n", (int)i);
    // while (tmp_list)
    // {
    //     if (tmp_list->n_arg_precision)

    //     else if (tmp_list->n_arg_width)
    //     else if (tmp_list->n_arg)
    //     tmp_list = tmp_list->next;
    // }
}

void    fill_struct_w_args(a_list *first_list, va_list ap)
{
    int     counter;
    int     latest_arg;

    latest_arg = find_latest_arg(first_list);
    counter = 0;
    // while (counter_arg <= latest_arg)
    counter++;
    put_the_arg(first_list, ap, counter);
    
    // printf("|%i|\n", latest_arg);
    // printf("|%i|\n", va_arg(ap, int));
    // while
}