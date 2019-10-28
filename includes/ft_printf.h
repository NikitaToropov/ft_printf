#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <locale.h> // dont rmmbr
# include <stdio.h> // dont rmmbr

#define LDBL_DIG 18
#define DBL_DIG 15

//Syntax:
//			%[parameter][flags][width][.precision][length]type

// FLAGS:
	// 	HASH == (char)1;
	// 	ZERO == (char)2;
	// 	MINUS == (char)4;
	// 	SPACE == (char)8;
	// 	PLUS == (char)16;
	// 	APOSTROPHE == (char)32;
	// 	BINARY == (char)64;

// LENGTH:
	// 	l == l;
	// 	ll == L;
	// 	h == h;
	// 	hh == H;
	// 	L == D;

typedef struct		t_list
{
	int				parameter; //bonus part - $
	int				n_arg_width;//not a vlue but number of arg 0-9, taken from IBM manual for width, hardcoded in original printf
	int				n_arg_precision;//"--"
	int				n_arg;//argument number can be more than 10

	int				width;//values of arguments - checked manually, in original printf they keep it in ints
	int				precision;//values of arguments - checked manually, in original printf they keep it in ints
	char			*arg;//values of arguments

	char			flags;
	char			length;
	char			type;

	struct t_list	*next;
}					s_args;

void		ft_error(void);

char		*ft_itoa(long long n);
char		*ft_itoa_base(unsigned long long n, int base);
char		*ft_itoa_base_uppercase(unsigned long long n, int base);
char		*ft_itoa_pointer(unsigned long long n);

int			ft_atoi(const char *str);
char		*ft_utf_8_coder(int sym);
char		*ft_put_bits(void *c, unsigned int len);

void		ft_clear_the_struct(s_args **first);
char		*ft_strchr(const char *s, int c);

void		ft_put_floating_arg(s_args *list, long double argument);
void		ft_put_integer_arg(s_args *list, unsigned long long arg);


int			ft_find_parameter(char *str, s_args *list);
int			ft_find_width(char *str, s_args *list);
int			ft_find_precision(char *str, s_args *list);
int			ft_find_length(char *str, s_args *list);
int			ft_find_flag(char symbol, s_args *list);
s_args		*ft_format_string_parse(char *str);

// s_args		*ft_make_struct(const char *format, ...);
int			ft_printf(const char *format, ...);

#endif