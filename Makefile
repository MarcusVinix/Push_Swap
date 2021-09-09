SRC_PATH = ./src/
PARSER_PATH = $(SRC_PATH)parser/
LIBFT_PATH = ./42libft/

LIBFT = $(LIBFT_PATH)libft.a
SRC =	$(SRC_PATH)main.c $(SRC_PATH)errors.c \
		$(PARSER_PATH)parser.c $(PARSER_PATH)stack_lst.c

NAME = push_swap

CC = clang
CFLAGS = -Werror -Wextra -Wall -fsanitize=address
RM = rm -rf

all:

$(NAME):

$(LIBFT):
	make -C $(LIBFT_PATH)
clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re

test: $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o teste

git:
	git add .
	git commit -m "making the parser of args"
	git push origin main
