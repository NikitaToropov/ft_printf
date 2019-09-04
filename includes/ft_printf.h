#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	long int		parameter;
	char			flags; // или  enum !!!!!!!!!!!!!!!!!!!!!!!!!!!!! исправ!
	long int		width; // узнать
	long int		precision; // тоже
	char			*lenght;
	char			type;
	void			*arg;
	struct s_list	*next;
}					a_list;

void		ft_error(int code);
char		*ft_strchr(const char *s, int c);
a_list		*ft_make_struct(const char *format, ...);
int			ft_printf(const char *format, ...);
// char	*ft_strchr(const char *s, int c);


#endif
