# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 19:37:13 by fjenae            #+#    #+#              #
#    Updated: 2019/09/05 21:52:27 by fjenae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR_CORE = objects_core
SRC_DIR_CORE = sources_core
OBJ_DIR_LIB = object_lib
SRC_DIR_LIB = libft

NAME_PRINTF = libftprintf.a
NAME_LIBFT = libft.a
NAME = 01_run

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER_PRINTF = printf.h
HEADER_LIBFT = ./libft/libft.h

SOURCES_CORE = printf.c

SOURCES_LIBFT = ft_memset.c \
 			ft_bzero.c \
 			ft_memcpy.c \
 			ft_memccpy.c \
 			ft_memmove.c \
 			ft_memchr.c \
  			ft_memcmp.c \
			ft_strlen.c \
 			ft_strdup.c \
 			ft_strcpy.c \
 			ft_strncpy.c \
 			ft_strcat.c \
 			ft_strncat.c \
 			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_isspace.c \
			ft_maxoftwo.c \
			ft_minoftwo.c \
			ft_sqrt.c \
			ft_islower.c \
			ft_isupper.c \
			ft_isxdigit.c \
			ft_str_is_lowercase.c \
			ft_str_is_uppercase.c

OBJECTS_CORE = $(addprefix $(OBJ_DIR_CORE)/, $(SOURCES_CORE:.c=.o))
OBJECTS_LIBFT = $(addprefix $(OBJ_DIR_LIB)/, $(SOURCES_LIBFT:.c=.o))

all: $(NAME)

$(NAME): $(NAME_PRINTF)
	$(CC) $(CFLAGS) main.c -L . -lftprintf -o $(NAME) 

$(NAME_PRINTF): $(OBJ_DIR_CORE) $(OBJ_DIR_LIB) $(OBJECTS_CORE) $(OBJECTS_LIBFT) 
	ar rc $(NAME_PRINTF) $(OBJECTS_CORE) $(OBJECTS_LIBFT)
	ranlib $(NAME_PRINTF)	

$(OBJ_DIR_CORE):
	mkdir objects_core 

$(OBJ_DIR_LIB):
	mkdir object_lib

$(OBJ_DIR_CORE)/%.o : $(SRC_DIR_CORE)/%.c $(HEADER_PRINTF)	
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

$(OBJ_DIR_LIB)/%.o : $(SRC_DIR_LIB)/%.c $(HEADER_LIBFT)
	$(CC) $(CFLAGS) -I ./libft -c $< -o $@

clean:
	rm -f $(OBJECTS_CORE)
	rm -f $(OBJECTS_LIBFT)
	rm -r $(OBJ_DIR_CORE)
	rm -r $(OBJ_DIR_LIB)
	rm -r $(NAME_PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all