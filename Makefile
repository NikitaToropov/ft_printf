NAME = libftprintf.a

# dirs
DIR_S = srcs

DIR_O = objs

INCLUDES = ./includes

# files
C_FILES = 	ft_printf.c\
			ft_format_string_parse.c\
			fields_parsers.c\
			ft_put_bits.c\
			ft_put_integer_arg.c\
			ft_put_floating_arg.c\
			ft_modify_str_arg.c\
			ft_precision_modifying.c\
			ft_error.c\
			ft_strchr.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_clear_the_struct.c\
			ft_itoa_base.c\
			ft_itoa.c\
			ft_atoi.c\
			ft_utf_8_coder.c\


HEADER = $(INCLUDES)/ft_printf.h

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))

OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra -g

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O):
	mkdir -p objs

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all