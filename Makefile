# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubin <yubchoi@student.42>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/12/26 16:46:24 by yubin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

CC		= cc
FLAGS	= -Wall -Wextra -Werror
DEBUG	= -g3 -fsanitize=address# TODO: remove
F/W		= -framework OpenGL -framework AppKit
RM		= rm -f

INC_DIR = ./includes/
SRC_DIR	= ./srcs/
MLX_DIR = ./mlx/
LIB_DIR = ./libft/

SRCS	= $(wildcard srcs/*.c) $(wildcard srcs/raycasting/*.c) $(wildcard srcs/calc/*.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	$(CC) $(DEBUG) $(F/W) $^ -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -o $(NAME)

%.o: %.c
	$(CC) $(DEBUG) -c $< -o $@ -I$(INC_DIR) -MJ $@.part.json

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re:
	make fclean
	make all

compile_commands.json:
	-$(MAKE) --always-make --keep-going all
	(echo '[' && cat srcs/*.part.json && echo ']') > $@

.PHONY: all clean fclean re compile_commands.json
