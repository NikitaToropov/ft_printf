# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 19:37:13 by fjenae            #+#    #+#              #
#    Updated: 2019/08/29 20:32:48 by fjenae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = printf

HEADERS = printf.h

OBJECTS = main.o

SOURCES = main.c

all: $(NAME)

$(NAME):$(OBJECTS)
		$(CC) $(CFLAGS) -o $(NAME) -L./Libft/ -lft $(OBJECTS)