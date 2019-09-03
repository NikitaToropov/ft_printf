NAME = libftprintf.a

# dirs
DIR_S = srcs

DIR_O = objs

INCLUDES = ./includes

# files
C_FILES = 	ft_printf.c\
			ft_errors.c

HEADER = includes/ft_printf.h

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))

OBJS = $(C_FILES:.c=.o)

# flags
FLAGS = -Wall -Werror -Wextra
CC = gcc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	mkdir -p objs
	
%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -c ./$< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all