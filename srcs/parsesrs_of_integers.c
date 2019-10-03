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

void    parse_types_uo(a_list *list, unsigned long long arg)
{
    else if (list->length == 'H')
    {
        if (list->type == 'u')
            list->arg = ft_itoa_base((unsigned char)arg, 10);
        if (list->type == 'o')
            list->arg = ft_itoa_base((unsigned char))arg, 8);
    }
    else if (list->length == 'h')
    {
        if (list->type == 'u')
            list->arg = ft_itoa_base((unsigned short)arg, 10);
        if (list->type == 'o')
            list->arg = ft_itoa_base((unsigned short)arg, 8);
    }
    else if (list->length == 'L')
    {
        if (list->type == 'u')
            list->arg = ft_itoa_base(arg, 10);
        if (list->type == 'o')
            list->arg = ft_itoa_base(arg, 8);
    }
    if (list->length == 'l')
    {
        if (list->type == 'u')
            list->arg = ft_itoa_base((unsigned long int)arg, 10);
        if (list->type == 'o')
            list->arg = ft_itoa_base((unsigned long int)arg, 8);
    }
    else
    {
        if (list->type == 'u')
            list->arg = ft_itoa_base((unsigned long int)arg, 10);
        if (list->type == 'o')
            list->arg = ft_itoa_base((unsigned long int)arg, 8);
    }
}

void    parse_types_xXp(a_list *list, unsigned long long arg)
{
    else if (list->length == 'H')
    {
        if (list->type == 'x' || list->type == 'p')
            list->arg = ft_itoa_base((unsigned char)arg, 16);
        if (list->type == 'X')
            list->arg = ft_ITOA_base((unsigned char)arg, 16);
    }
    else if (list->length == 'h')
    {
        if (list->type == 'x')
            list->arg = ft_itoa_base((unsigned char)arg, 16);
        if (list->type == 'X')
            list->arg = ft_ITOA_base((unsigned char)arg, 16);
    }
    else if (list->length == 'L')
    {
        if (list->type == 'x')
            list->arg = ft_itoa_base((unsigned char)arg, 16);
        if (list->type == 'X')
            list->arg = ft_ITOA_base((unsigned char)arg, 16);
    }
    else if (list->length == 'l')
    {
        if (list->type == 'x')
            list->arg = ft_itoa_base((unsigned char)arg, 16);
        if (list->type == 'X')
            list->arg = ft_ITOA_base((unsigned char)arg, 16);
    }
    else
    {
        if (list->type == 'x')
            list->arg = ft_itoa_base((unsigned char)arg, 16);
        if (list->type == 'X')
            list->arg = ft_ITOA_base((unsigned char)arg, 16);
    }
    if (list->type == 'p')
        ft_itoa_pointer(arg);
}