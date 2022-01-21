# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:42:18 by cberganz          #+#    #+#              #
#    Updated: 2022/01/21 16:05:37 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

INCLUDE		= includes/

HEADER		= ${INCLUDE}so_long.h

CC		= clang

CFLAGS		= -Wall -Wextra -Werror

SRC_NAME	= main.c				\
		  initialize_map.c			\
		  initialize_map_checker.c	\
		  initialize_window.c		\
		  initialize_img.c			\
		  initialize_game.c			\
		  game.c					\
		  exit_game.c				\
		  utils.c

SRC_BONUS_NAME	= main.c			\
		  initialize_map.c			\
		  initialize_map_checker.c	\
		  initialize_window.c		\
		  initialize_img.c			\
		  initialize_game.c			\
		  game.c					\
		  exit_game.c				\
		  utils.c

SRC_DIR		= src/
SRC		= ${addprefix ${SRC_DIR}, ${SRC_NAME}}

OBJ_DIR		= objs/
OBJ_DIRS	= ${sort ${dir ${OBJ}}}
OBJ_NAME	= ${SRC_NAME:.c=.o}
OBJ		= ${addprefix ${OBJ_DIR}, ${OBJ_NAME}}

SRC_BONUS_DIR		= src_bonus/
SRC_BONUS		= ${addprefix ${SRC_BONUS_DIR}, ${SRC_BONUS_NAME}}

OBJ_BONUS_DIR		= objs_bonus/
OBJ_BONUS_DIRS	= ${sort ${dir ${OBJ_BONUS}}}
OBJ_BONUS_NAME	= ${SRC_BONUS_NAME:.c=.o}
OBJ_BONUS		= ${addprefix ${OBJ_BONUS_DIR}, ${OBJ_BONUS_NAME}}

all: ${NAME}

$(NAME): $(OBJ)
	@make -sC ./libft/
	@make -sC ./mlx-linux/
	$(CC) $(CFLAGS) -L./libft ${OBJ} -lft -Lmlx-linux -lmlx_Linux -L/usr/lib -Ilibmlx_linux -lXext -lX11 -lm -lz -o $(NAME) -g3

bonus: $(OBJ_BONUS)
	@make -sC ./libft/
	@make -sC ./mlx-linux/
	$(CC) $(CFLAGS) -L./libft ${OBJ_BONUS} -lft -Lmlx-linux -lmlx_Linux -L/usr/lib -Ilibmlx_linux -lXext -lX11 -lm -lz -o $(NAME) -g3

${OBJ_DIRS}:
	mkdir -p $@

${OBJ_BONUS_DIRS}:
	mkdir -p $@

${OBJ}: | ${OBJ_DIRS}
${OBJ_BONUS}: | ${OBJ_BONUS_DIRS}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADER}
	${CC} ${CFLAGS} -I${INCLUDE} -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g3

${OBJ_BONUS_DIR}%.o: ${SRC_BONUS_DIR}%.c ${HEADER}
	${CC} ${CFLAGS} -I${INCLUDE} -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g3

clean:
	@make clean -sC ./libft/
	@make clean -sC ./mlx-linux/
	rm -rf ${OBJ_DIR}
	rm -rf ${OBJ_BONUS_DIR}

fclean: clean
	@make fclean -sC ./libft/
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
