# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/12/25 05:09:02 by son-yeong-w      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

CC		= cc
FLAGS	= -Wall -Wextra -Werror
F/W     =   -framework OpenGL -framework AppKit
RM		= rm -f

INC_DIR = ./includes/
SRC_DIR	= ./srcs/
MLX_DIR = ./mlx/
LIB_DIR = ./libft/

SRCS	= $(wildcard srcs/*.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	$(CC) $(FLAGS) $(F/W) $^ -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx  -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

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

PHONY: all clean fclean re
