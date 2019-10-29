#include "ft_printf.h"

void	ft_precision_p(s_args *list)
{
	int		len;
	int		new_len;
	char	*str;

	len = ft_strlen(list->arg);
	new_len = list->precision + 2;
	if (len < new_len)
	{
		str = (char*)malloc(sizeof(char) * (new_len + 1));
		str[new_len] = '\0';
		new_len--;
		len--;
		while (new_len >= 0)
		{
			if (len > 1 || len == new_len)
			{
				str[new_len] = (list->arg)[len];
				len--;
			}
			else
				str[new_len] = '0';
			new_len--;
		}
		free(list->arg);
		list->arg = str;
	}
}

void	ft_precision_modifying(s_args *list)
{
	if (list->type == 'p')
		ft_precision_p(list);
	// if (list->type == 'f')
	// 	ft_precision_f(list);

}