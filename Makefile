# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 13:43:40 by beldemir          #+#    #+#              #
#    Updated: 2025/02/22 18:49:26 by beldemir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
SRCS = ./src/main.c \
		./src/init.c \
		./src/utils.c \
		./src/hooks.c \
		./src/palette.c \
		./src/move.c \
		./src/mandelbrot.c \
		./src/julia.c \
		./include/ft_printf.c 
OBJS = $(SRCS:.c=.o)
BONUSSRCS = ./src_bonus/main_bonus.c \
		./src_bonus/init_bonus.c \
		./src_bonus/utils_bonus.c \
		./src_bonus/hooks_bonus.c \
		./src_bonus/palette_bonus.c \
		./src_bonus/move_bonus.c \
		./src_bonus/mandelbrot_bonus.c \
		./src_bonus/julia_bonus.c \
		./src_bonus/feature_bonus.c \
		./include/ft_printf.c 
BONUSOBJS = $(BONUSSRCS:.c=.o)
FLAGS = -I./include/mlx -L./include/mlx -lmlx -lX11 -lXext -lm -pthread

all: $(NAME)

$(NAME):$(OBJS)
	@make -C ./include/mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

bonus:$(BONUSOBJS)
	@make -C ./include/mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(BONUSOBJS) $(FLAGS)

clean:
	@rm -rf ./src/*.o
	@rm -rf ./src_bonus/*.o
	@rm -rf ./include/*.o

fclean: clean
	@rm -rf fractol

re: fclean all

.PHONY: all clean fclean re
