#include "ft_printf.h"

void    ft_check_the_valid(a_list *list)
{
    int     param;
    int     real_nums;
    int     long_real_nums;
    int     int_nums;

    param = 0;
    real_nums = 0;
    long_real_nums = 0;
    int_nums = 0;
    while (list)
    {
        if (list->param_field)
            param = 1;
        if (list->n_arg_width || list->n_arg_precision ||
        list->type == 'i' || list->type == 'd' ||
        list->type == 'c' || list->type == 's' ||
        list->type == 'x' || list->type == 'X' ||
        list->type == 'u' || list->type == 'o' ||
        list->type == 'p')
            int_nums = 1;
        if (list->type == 'f')
        {
            if (list->length == 'F')
                long_real_nums = 1;
            else
                real_nums = 1;
        }
        list = list->next;
    }
    if (param && ((real_nums && int_nums) || (long_real_nums && int_nums)))
        ft_error(2);
    else if (param && real_nums && long_real_nums)
        ft_error(3);
}
