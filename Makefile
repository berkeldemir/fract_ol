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
MLX_DIR = ./include/mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
SRCS = ./src/main.c \
		./src/init.c \
		./src/utils.c \
		./src/hooks.c \
		./src/mandelbrot.c \
		./src/color.c \
		./src/move.c \
		./src/julia.c \
		./include/ft_printf.c
OBJS = $(SRCS:.c=.o)
BONUSSRCS = ./src_bonus/main_bonus.c \
			./src_bonus/init_bonus.c \
			./src_bonus/utils_bonus.c \
			./src_bonus/hooks_bonus.c \
			./src_bonus/mandelbrot_bonus.c \
			./src_bonus/color_bonus.c \
			./src_bonus/move_bonus.c \
			./src_bonus/julia_bonus.c \
			./src_bonus/feature_bonus.c \
			./include/ft_printf.c
BONUSOBJS = $(BONUSSRCS:.c=.o)
FLAGS = -I./include/mlx -L./include/mlx -lmlx -lX11 -lXext -lm

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

bonus: $(BONUSOBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(BONUSOBJS) $(FLAGS)

clean:
	@rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	@rm -f fractol

re: fclean all

.PHONY: all bonus clean fclean re