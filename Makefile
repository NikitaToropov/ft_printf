# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 19:37:13 by fjenae            #+#    #+#              #
#    Updated: 2019/09/04 21:48:23 by fjenae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR_CORE = objects_core
SRC_DIR_CORE = sources_core
OBJ_DIR_LIB = object_lib
SRC_DIR_LIB = sources_lib

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAMEPRINTF = printflib.a
NAMELIBFT = libft.a

HEADERS = printf.h

SOURCES_CORE = printf.c

OBJECTS_CORE = $(addprefix $(OBJ_DIR_CORE)/, $(SOURCES_CORE:.c=.o))

all: $(NAMEPRINTF)

$(NAMEPRINTF):$(OBJECTS)
		$(CC) $(CFLAGS) -o $(NAME) -L./Libft/ -lft $(OBJECTS)

lib:
	make -C./libft
