NAME = libftprintf.a

# dirs
DIR_S = srcs

DIR_O = obj

DIR_L = libft

INCLUDES = includes

# files
C_FILES = 	ft_printf.c\
			ft_errors.c
			
SRCS = $(addprefix $(DIR_S)/,$(C_FILES))

OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o)))

# flags
FLAGS = -Wall -Werror -Wextra
CC = gcc

.PHONY: all clean fclean re

all: $(NAME)

$(DIR_O):
	mkdir -p $(DIR_O)
	make -C $(DIR_L)

$%(OBJS):$%(SRCS)
	$(CC) $(FLAGS) -I ./$(INCLUDES) -c $< -o $@

$(NAME): $(DIR_O) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)



# $(DIR_O):



# $(NAME): $(DIR_O)

# $(DIR_O): $(DIR_L)
	
# $(DIR_L):

# $(OBJS)/%.c:$(SRCS)/.o
# 	mkdir -p obj



# $(NAME): $(OBJS) 
# #	$(CC) $(FLAGS) $(OBJS) -I $(INCLUDES) -c $< -o $@
# 	make -C $(DIR_L)

# $%(OBJS):$%(SRCS)
# 	$(CC) $(FLAGS) -I $(INCLUDES) -c $@ -o $<
# 	# -L ./libft -lft 

# #$(NAME):  $(DIR_O)/%.o
# #	mkdir obj

# #$(DIR_O)/%.o: $(DIR_S)/%.c $(INCLUDES)/ft_printf.h
# #	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

# $(NAMELIBFT):
# 	make -C $(DIR_L)
	
clean:
	rm -rf obj
	make clean -C $(DIR_L)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(DIR_L)

re: fclean all