#include "ft_printf.h"

void	ft_clear_the_struct(s_args **first)
{
	s_args		*tmp;

	while (*first)
	{
		tmp = *first;
		*first = tmp->next;
		free(tmp);
		// free(tmp1->flags);
		// free(tmp1->lenght);
		// free(tmp1->args);
	}
	first = NULL;
}