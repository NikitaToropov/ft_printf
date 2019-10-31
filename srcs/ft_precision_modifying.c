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

void	ft_new_str_f(s_args *list, int old_len, int new_len)
{
	char	*tmp;
	int		counter;

	tmp = list->arg;
	if (!(list->arg = (char*)malloc(sizeof(char) * (new_len + 1))))
		ft_error(1);
	list->arg[new_len] = '\0';
	counter = 0;
	while (counter < new_len)
	{
		if (counter < old_len)
			list->arg[counter] = tmp[counter];
		else
			list->arg[counter] = '0';
		counter++;
	}
	free(tmp);
}

void	ft_precision_f(s_args *list)
{
	int		frac_len;
	int		old_len;
	int		new_len;

	if (list->precision == -1)
		list->precision = 6;
	old_len = ft_strlen(list->arg);
	new_len = ft_strchr(list->arg, '.') - list->arg;
	frac_len = ft_strlen(list->arg);
	if (list->precision == frac_len)
		return ;
	else if (!list->precision && list->arg[0] == '-' && list->arg[1] == '0')
	{
		free(list->arg);
		list->arg = ft_strdup("0");
		return ;
	}
	else if (list->precision > frac_len || list->precision < frac_len)
		new_len += list->precision + 1;
	ft_new_str_f(list, old_len, new_len);
}

void	ft_precision_modifying(s_args *list)
{
	int		old_len;

	if (list->type == 'f' && !(list->flags & BIN_FLAG))
			ft_precision_f(list);
	else if (list->type == 'p' && list->precision != -1 &&
	!(list->flags & BIN_FLAG))
			ft_precision_p(list);
	else if (list->precision != -1 && list->type == 's')
	{
		old_len = ft_strlen(list->arg);
		if (old_len > list->precision)
			list->arg[list->precision] = '\0';
	}
}