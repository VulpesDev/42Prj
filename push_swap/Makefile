# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/01/21 13:16:25 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = push_swap.c error_handling.c atol.c

OBJ = $(SRC:.c=.o)

PRINTF_NAME = libftprintf.a

LIBFT_NAME = libft.a

PRINTF_FOLDER = ./ft_printf

LIBFT_FOLDER = ./libft

all: $(NAME) 

.c.o:
	$(CC) -O3 -c $< -o $@ -g

libft_ftprintf:
	cd $(PRINTF_FOLDER) && make all
	cd $(LIBFT_FOLDER) && make all

$(NAME): $(OBJ) libft_ftprintf
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
