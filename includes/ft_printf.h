#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // dont rmmbr

typedef struct		s_list
{
	long int		parameter;
	char			flags; // или  enum !!!!!!!!!!!!!!!!!!!!!!!!!!!!! исправ!
	long int		width; // узнать
	long int		precision; // тоже
	char			*lenght;
	char			type; //OK
	void			*arg;
	struct s_list	*next;
}					a_list;

void		ft_error(int code);
void		ft_clear_the_struct(a_list **first);
char		*ft_strchr(const char *s, int c);
a_list		*ft_make_struct(const char *format, ...);
int			ft_printf(const char *format, ...);
// char	*ft_strchr(const char *s, int c);


#endif
