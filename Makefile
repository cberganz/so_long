# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:42:18 by cberganz          #+#    #+#              #
#    Updated: 2022/01/14 05:06:16 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

INCLUDE		= includes/

HEADER		= ${INCLUDE}so_long.h

CC		= clang

CFLAGS		= -Wall -Wextra -Werror

SRC_NAME	= main.c		\
		  init_struct.c		\
		  init_map.c		\
		  utils_clear_memory.c	\
		  check_map.c


SRC_DIR		= src/
SRC		= ${addprefix ${SRC_DIR}, ${SRC_NAME}}

OBJ_DIR		= objs/
OBJ_DIRS	= ${sort ${dir ${OBJ}}}
OBJ_NAME	= ${SRC_NAME:.c=.o}
OBJ		= ${addprefix ${OBJ_DIR}, ${OBJ_NAME}}

all: ${NAME}

$(NAME): $(OBJ)
	$(MAKE) -C ./libft/
	$(CC) $(CFLAGS) -L./libft ${OBJ} -lft -o $(NAME) -g3

${OBJ_DIRS}:
	mkdir -p $@

${OBJ}: | ${OBJ_DIRS}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADER}
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@ -g3

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
