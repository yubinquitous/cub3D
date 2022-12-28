# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 09:15:47 by kijsong           #+#    #+#              #
#    Updated: 2022/12/28 16:56:48 by yubchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -MMD -MP
ARFLAGS = rcs

SRCDIR = ./src
OBJDIR = ./obj

CTYPE = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c \
		ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_tolower.c \
		ft_toupper.c
LIST = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	   ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
STDIO = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		get_next_line.c
STDLIB = ft_atoi.c ft_itoa.c safe_malloc.c ft_calloc.c ft_free.c
STRING = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		 ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strspn.c \
		 ft_strcspn.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		 ft_strcmp.c ft_strncmp.c ft_strdup.c ft_substr.c ft_strjoin.c \
		 ft_strtrim.c ft_strsep.c ft_strtok.c ft_split.c ft_strmapi.c \
		 ft_striteri.c

SRC = $(CTYPE) $(STDIO) $(STDLIB) $(STRING)
SRC_B = $(LIST)

SRCS = $(SRC) $(if $(filter bonus,$(MAKECMDGOALS)),$(SRC_B))
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

.DEFAULT_GOAL = all

-include $(DEPS)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/*/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean:
	$(MAKE) -s clean
	$(RM) $(NAME)

re:
	$(MAKE) -s fclean
	$(MAKE) -s all

.PHONY: all bonus clean fclean re
