# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/02/05 11:42:21 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

NAME_BONUS = checker

SRC = push_swap.c error_handling.c atol.c stack_operations.c stack_operations_subject.c \
stack_operations_print.c stack_operations_print2.c find_functions.c other_functions.c \
get_functions.c sorting_functions.c sort_small.c

SRC_BONUS = stack_operations.c main_bonus.c error_handling.c get_next_line_bonus.c \
get_next_line_utils_bonus.c atol.c stack_operations_subject_bonus.c \
other_functions.c find_functions.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

PRINTF_NAME = libftprintf.a

LIBFT_NAME = libft.a

PRINTF_FOLDER = ./ft_printf

LIBFT_FOLDER = ./libft

all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

$(PRINTF_FOLDER)/$(PRINTF_NAME):
	cd $(PRINTF_FOLDER) && make all

$(LIBFT_FOLDER)/$(LIBFT_NAME):
	cd $(LIBFT_FOLDER) && make all

$(NAME): $(OBJ) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME)
	$(CC) $(OBJ) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME)
	$(CC) $(OBJ_BONUS) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME) -o $(NAME_BONUS)

clean:
	cd $(PRINTF_FOLDER) && make clean
	cd $(LIBFT_FOLDER) && make clean
	-rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	cd $(PRINTF_FOLDER) && make fclean
	cd $(LIBFT_FOLDER) && make fclean
	-rm -f $(NAME) $(NAME_BONUS)

re: fclean all
