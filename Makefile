NAME = libftprintf.a

SRCS = ./srcs/*.c

OBJECTS = ./*.o

FLAG = -Wall -Werror -Wextra

INCLUDES = ./

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all