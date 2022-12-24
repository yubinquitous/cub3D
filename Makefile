# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoson <yoson@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:11:41 by kijsong           #+#    #+#              #
#    Updated: 2022/12/23 17:21:48 by yoson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC_DIR	= ./srcs/
LIB_DIR = ./libft/

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

PHONY: all clean fclean re
