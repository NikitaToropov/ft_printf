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

void	ft_precision_f(s_args *list)
{
	int		frac_len;
	int		int_len;
	int		new_len;
	int		counter;
	char	*tmp;


	if (list->precision == -1)
		list->precision = 6;

	tmp = ft_strchr(list->arg, '.') + 1;

	frac_len = ft_strlen(tmp);
	int_len = tmp - list->arg - 1;
	tmp = list->arg;
	
	if (list->precision == frac_len)
		return ;
	else if (list->precision == 0)
	{
		if (list->arg[0] == '-' && list->arg[1] == '0')
		{
			free(list->arg);
			list->arg = "0";
			return ;
		}
		new_len = int_len;
	}
	else
		new_len = int_len + list->precision + 1;

	if (!(list->arg = (char*)malloc(sizeof(char) * (new_len + 1))))
		ft_error(1);
	list->arg[new_len] = '\0';
	counter = 0;
	while (counter < new_len)
	{
		if (tmp[counter])
			list->arg[counter] = tmp[counter];
		else
			list->arg[counter] = '0';
		counter++;
	}
	free(tmp);
}

void	ft_precision_modifying(s_args *list)
{
	if (!(list->flags & BIN_FLAG))
	{
		if (list->type == 'f')
			ft_precision_f(list);

	}
	else if (list->precision != -1 && !(list->flags & BIN_FLAG))
	{
		if (list->type == 'p')
			ft_precision_p(list);
	}

}