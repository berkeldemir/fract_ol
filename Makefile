# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 13:43:40 by beldemir          #+#    #+#              #
#    Updated: 2025/02/12 17:33:54 by beldemir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = #-Wall -Wextra -Werror
NAME = fractol
SRCS = ./src/main.c \
		./src/init.c \
		./src/utils.c \
		./src/hooks.c \
		./src/mandelbrot.c \
		./include/ft_printf.c
FLAGS = -I./include/mlx -L./include/mlx -lmlx -lX11 -lXext -lm -pthread

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(FLAGS)

clean:
	rm -f fractol

fclean: clean

re: fclean all

.PHONY: all clean fclean re