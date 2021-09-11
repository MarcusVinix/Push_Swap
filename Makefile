# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 10:10:37 by mavinici          #+#    #+#              #
#    Updated: 2021/09/10 21:39:06 by mavinici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
PARSER_PATH = $(SRC_PATH)parser/
COMM_PATH = $(SRC_PATH)commands/
LIBFT_PATH = ./42libft/

LIBFT = $(LIBFT_PATH)libft.a
SRC =	$(SRC_PATH)main.c $(SRC_PATH)errors.c \
		$(PARSER_PATH)parser.c $(PARSER_PATH)stack_lst.c \
		$(COMM_PATH)sa_b.c $(COMM_PATH)pa_b.c $(COMM_PATH)ra_b.c $(COMM_PATH)rra_b.c

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
	git commit -m "make the commands sa, pa, ra, rr"
	git push origin main
