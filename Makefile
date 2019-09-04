# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 19:37:13 by fjenae            #+#    #+#              #
#    Updated: 2019/09/04 21:28:38 by fjenae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR_CORE = objects_core

SRC_DIR_CORE = sources

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = printflib.a

HEADERS = printf.h

SOURCES = printf.c

OBJECTS = $()



all: $(NAME)

$(NAME):$(OBJECTS)
		$(CC) $(CFLAGS) -o $(NAME) -L./Libft/ -lft $(OBJECTS)