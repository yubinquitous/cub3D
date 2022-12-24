NAME	= cub3D

CC		= gcc
# CFLAGS	= -Wall -Werror -Wextra`
CLIB	= -L./mlx -lmlx \
		-framework OpenGL -framework AppKit

RM		= rm -f

SRCS	= img_raycasting.c
OBJS	= $(SRCS:%.c=%.o)

MLX		= mlx

.PHONY:	all
all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./$(MLX)	
	$(CC) $(CLIB) $(SRCS) -o $(NAME)

.PHONY:	clean
clean:
	$(MAKE) clean -C ./$(MLX)
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME)

.PHONY:	re
re:	
	$(MAKE) fclean
	$(MAKE) all