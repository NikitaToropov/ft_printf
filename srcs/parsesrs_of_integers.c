#include "ft_printf.h"

void	parse_simple_integer(a_list *list, unsigned long long arg)
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

void	parse_unsigned_integer(a_list *list, unsigned long long arg)
{
    ft_itoa_base_uns(arg, list);

}

// void	parse_pointer_integer(a_list *list, unsigned long long arg)

// void	parse_string_integer(a_list *list, unsigned long long arg)

// void	parse_char_integer(a_list *list, unsigned long long arg)