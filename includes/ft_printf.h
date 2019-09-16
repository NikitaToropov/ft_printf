#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // dont rmmbr

typedef struct		s_list
{
	unsigned int	parameter;// помни что порядок наследуется (см. тетрадь)
	char			flags;//OK 5 вариантов, хватит 3х битов

	int				width;//OK хватит границ инта
	int				n_arg_width;//OK если есть '*', то > 0	

	long int		precision;
	int				n_arg_precision;//OK если есть '*', то > 0	

	char			lenght;//OK побитово 4 варианта
	char			type;//OK 11 вариантов, хватит 4х битов

	char			*arg;//OK будем хранить строку
	int				n_arg;
	
	struct s_list	*next;
}					a_list;

char		*ft_itoa(long long n);
char		*ft_uns_itoa_base_wregister(unsigned long long n, unsigned int base, int X);
void		ft_error(int code);
void		ft_clear_the_struct(a_list **first);
char		*ft_strchr(const char *s, int c);
a_list		*ft_make_struct(const char *format, ...);
int			ft_printf(const char *format, ...);
// char	*ft_strchr(const char *s, int c);


#endif
