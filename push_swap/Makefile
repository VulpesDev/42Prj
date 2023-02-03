# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/02/03 15:39:09 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = push_swap.c error_handling.c atol.c stack_operations.c stack_operations_subject.c \
stack_operations_print.c stack_operations_print2.c find_functions.c other_functions.c \
get_functions.c sorting_functions.c

OBJ = $(SRC:.c=.o)

PRINTF_NAME = libftprintf.a

LIBFT_NAME = libft.a

PRINTF_FOLDER = ./ft_printf

LIBFT_FOLDER = ./libft

all: $(NAME) 

.c.o:
	$(CC) -O3 -c $< -o $@ -g

$(PRINTF_FOLDER)/$(PRINTF_NAME):
	cd $(PRINTF_FOLDER) && make all

$(LIBFT_FOLDER)/$(LIBFT_NAME):
	cd $(LIBFT_FOLDER) && make all

$(NAME): $(OBJ) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME)
	$(CC) $(OBJ) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME) -o $(NAME)

clean:
	cd $(PRINTF_FOLDER) && make clean
	cd $(LIBFT_FOLDER) && make clean
	-rm -f $(OBJ) $(OBJ_CLIENT)

fclean: clean
	cd $(PRINTF_FOLDER) && make fclean
	cd $(LIBFT_FOLDER) && make fclean
	-rm -f $(NAME) $(NAME_CLIENT)

re: fclean all
