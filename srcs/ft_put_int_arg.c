#include "ft_printf.h"

void    ft_put_int_arg(a_list *list, unsigned long long arg)
{
    if (list->type == 'd' || list->type == 'i' || list->type == 'u')
    else if (list->type == 'x' || list->type == 'X' || list->type == 'p')
    else if (list->type == 'o')
    else if (list->type == 'c')
    else if (list->type == 's')
}