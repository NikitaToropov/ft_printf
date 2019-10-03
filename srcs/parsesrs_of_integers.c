#include "ft_printf.h"

void	parse_types_di(a_list *list, unsigned long long arg)
{
    if (list->length == 'l')
        list->arg = ft_itoa((long int)arg);
    else if (list->length == 'L')
        list->arg = ft_itoa(arg);
    else if (list->length == 'h')
        list->arg = ft_itoa((short)arg);
    else if (list->length == 'H')
        list->arg = ft_itoa((char)arg);
    else
        list->arg = ft_itoa((int)arg);
}

void    parse_types_uoxXp(a_list *list, unsigned long long arg)
{
    if (list->length == 'l')
    {
        if (list->type == 'u')
            
    }
        list->arg = ft_itoa((long int)arg);
    else if (list->length == 'L')
        list->arg = ft_itoa(arg);
    else if (list->length == 'h')
        list->arg = ft_itoa((short)arg);
    else if (list->length == 'H')
        list->arg = ft_itoa((char)arg);
    else
        list->arg = ft_itoa((int)arg);
}