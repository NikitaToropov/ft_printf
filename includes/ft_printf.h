#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"




typedef struct		m_list
{
	char			flags[6]; // или  enum
	long int		width; // узнать
	long int		precision; // тоже
	char			*lenght;
	char			type;
	void			*arg;
	struct s_list	*next;
}					a_list;

void		ft_error(int code);
int			ft_printf(const char *format, ...);
// char	*ft_strchr(const char *s, int c);


#endif
