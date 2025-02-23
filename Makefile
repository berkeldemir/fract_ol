# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 13:43:40 by beldemir          #+#    #+#              #
#    Updated: 2025/02/22 14:37:10 by beldemir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
SRCS = ./src/main.c \
		./src/init.c \
		./src/utils.c \
		./src/hooks.c \
		./src/mandelbrot.c \
		./src/color.c \
		./src/move.c \
		./src/julia.c \
		./src/feature.c \
		./include/ft_printf.c
OBJS = $(SRCS:.c=.o)
FLAGS = -I./include/mlx -L./include/mlx -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f fractol

re: fclean all

.PHONY: all clean fclean re