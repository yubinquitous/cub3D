# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/12/27 15:38:10 by kijsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

FLAGS	= -Wall -Wextra -Werror
F/W		= -framework OpenGL -framework AppKit

INC_DIR = ./includes/
SRC_DIR	= ./srcs/
MLX_DIR = ./mlx/
LIB_DIR = ./libft/

CALC	= dda.c texture.c wall.c
KEY		= key_event.c look.c move.c
RAYCAST	= raycasting.c load_texture.c
SRC		= common_error.c main.c parser_element_utils.c parser_map_utils.c \
		  parser_utils.c parser.c utils.c

IN_SRCS	= $(addprefix ./calc/, $(CALC)) $(addprefix ./key_press/, $(KEY)) \
		  $(addprefix ./raycasting/, $(RAYCAST)) $(SRC)
SRCS	= $(addprefix ./srcs/, $(IN_SRCS))
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	$(CC) $(FLAGS) $(F/W) $^ -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR) -MJ $@.part.json

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)
	find ./ -name "*.json" -type f -exec $(RM) {} +

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

compile_commands.json:
	-$(MAKE) --always-make --keep-going all
	(echo '[' && cat **/*.part.json && echo ']') > $@

.PHONY: all clean fclean re compile_commands.json
