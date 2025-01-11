CC = cc
CFLAGS = -Wall -Wextra -Werror

all: 

clean:
	rm -rf 

fclean: clean
	rm -rf

re: fclean all

.PHONY: all clean fclean re