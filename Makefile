SRC_PATH = ./src/
LIBFT_PATH = ./42libft/

LIBFT = $(LIBFT_PATH)libft.a

SRC = $(SRC_PATH)main.c $(SRC_PATH)parser.c

NAME = push_swap

CC = clang
CFLAGS = -Werror -Wextra -Wall -fsanitize=address
RM = rm -rf

all:

$(NAME):

$(LIBFT):
	make -C $(LIBFT_PATH)
clean:

fclean: clean

re: fclean all

.PHONY: all clean fclean re

test: $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o teste

git:
	git add .
	git commit -m "starting store the args"
	git push origin main
