# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcus <marcus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 10:10:37 by mavinici          #+#    #+#              #
#    Updated: 2022/01/03 18:25:43 by marcus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
PARSER_PATH = $(SRC_PATH)parser/
COMM_PATH = $(SRC_PATH)commands/
SORT_PATH = $(SRC_PATH)sort/
LIBFT_PATH = ./42libft/
PATH_OBJS = ./objs/

LIBFT = $(LIBFT_PATH)libft.a

SRC =	$(SRC_PATH)main.c $(SRC_PATH)errors.c \
		$(PARSER_PATH)parser.c $(PARSER_PATH)stack_lst.c \
		$(COMM_PATH)sa_b.c $(COMM_PATH)pa_b.c $(COMM_PATH)ra_b.c $(COMM_PATH)rra_b.c \
		$(SORT_PATH)sort_stack.c $(SORT_PATH)sort_min.c $(SORT_PATH)sort_list.c $(SORT_PATH)utils_sort.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

NAME = push_swap

CC = clang
CFLAGS = -Werror -Wextra -Wall -fsanitize=address
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)src/commands
	@mkdir -p $(PATH_OBJS)src/parser
	@mkdir -p $(PATH_OBJS)src/sort
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(PATH_OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

test: $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

git:
	git add .
	git commit -m "Making the readme"
	git push origin main
