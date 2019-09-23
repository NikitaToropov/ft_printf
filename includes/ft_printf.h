#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <locale.h> // dont rmmbr
# include <stdio.h> // dont rmmbr


//Processing order:
//			1. format string parsing "ft_make_struct"
//			2. va_arg parsing depending on:
//				A. smallest arguments (all struct) in:
//					a. "parameter" (int)
//					b. "n_arg_width" (int)	
//				 	c. "n_arg_precision" (int)
//					d. "n_arg" (int -> signed/unsigned long long, *void, )
//			3. argument string modifying:
//				A. length (malloc)
//				B. precision (malloc, free)
//				C. width (malloc, free)
//				D. flags (malloc, free)
//			4. 

//Syntax:
//			%[parameter][flags][width][.precision][length]type

typedef struct		s_list
{
	int				parameter;//OK помни что порядок наследуе	тся (см. тетрадь)
	char			flags;//OK 5 вариантов, хватит 3х битов

// FLAGS:
	// 	HASH == (char)1;
	// 	ZERO == (char)2;
	// 	MINUS == (char)4;
	// 	MINUS == (char)8;
	// 	MINUS == (char)16;
	// 	APOSTROPHE == (char)32;

	int				width;//хватит границ инта
	int				n_arg_width;//если есть '*', то > 0	

	int				precision;
	int				n_arg_precision;//если есть '*', то > 0	

	char			length;//OK побитово 4 варианта

	char			type;//OK s,c,p,i/d,x,X,u,o,f,% (12)
	// i = d => d

	char			*arg;// будем хранить строку
	int				n_arg;
	unsigned int				n_of_list; //ok
	
	struct s_list	*next; //OK
}					a_list;

char		ft_find_type(char *str);
int			is_it_parameter(char *str, a_list *list);
int			is_it_flag(char symbol, a_list *list);
int			is_it_length(char *str, a_list *list);
int			is_it_width(char *str, a_list *list);
int			is_it_precission(char *str, a_list *list);



int			ft_atoi(const char *str);
char		*ft_itoa(long long n);
char		*ft_uns_itoa_base_wregister(unsigned long long n, int base, int X);
void		ft_error(int code);
void		ft_clear_the_struct(a_list **first);
char		*ft_strchr(const char *s, int c);
a_list		*ft_make_struct(const char *format, ...);
int			ft_printf(const char *format, ...);
// char	*ft_strchr(const char *s, int c);


#endif
