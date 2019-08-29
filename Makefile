NAME = libftprintf.a

# dirs
DIR_S = srcs

DIR_O = objs

DIR_L = libft

INCLUDES = ./

# files
SOURCES = *.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/, $(SOURCES:.c=.o))

FLAG = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(DIR_L)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(INCLUDES)/ft_printf.h
	@mkdir -p obj
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

	# @gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(SRCS)
	# @ar rc $(NAME) $(OBJECTS)
	# @ranlib $(NAME)
	# @gcc -c main.c
	# @gcc -o letsDoIt main.o -L. -lftprintf
	# @./letsDoIt
clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@make clean -C $(DIR_L)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(DIR_L)
	# @rm letsDoIt
re: fclean all