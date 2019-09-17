#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // dont rmmbr

//Syntax:
//			%[parameter][flags][width][.precision][length]type

//Processing order:
//			1. format string parsing
//			2. va_arg parsing depending on:
//				A. smallest arguments (all struct) in:
//					a. "n_arg_width" (int)
//				 	b. "n_arg_precision" (int)
//					c. "n_arg" (int -> signed/unsigned long long, *void, )
//			3. argument string modifying:
//				A. length (malloc)
//				B. precision (malloc, free)
//				C. width (malloc, free)
//				D. flags (malloc, free)
//			4. printing


typedef struct		s_list
{
	unsigned int	parameter;// помни что порядок наследуется (см. тетрадь)
	char			flags;//OK 5 вариантов, хватит 3х битов

	int				width;//OK хватит границ инта
	int				n_arg_width;//OK если есть '*', то > 0	

	long int		precision;
	int				n_arg_precision;//OK если есть '*', то > 0	

	char			length;//OK побитово 4 варианта
	char			type;//OK s,c,p,i/d,x,X,u,o,f,% (11)

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
