# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/01/08 10:43:01 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

SRC = main.c event_handler.c management_calc.c sets.c print_management.c

OBJ = $(SRC:.c=.o)

PRINTF_FOLDER = ./ft_printf

all: $(NAME)

.c.o:
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g

$(NAME): $(OBJ)
	cd mlx_linux && ./configure
	cd $(PRINTF_FOLDER) && make all
	$(CC) $(OBJ) $(PRINTF_FOLDER)/libftprintf.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	cd $(PRINTF_FOLDER) && make clean
	-rm -f $(OBJ)

fclean: clean
	cd $(PRINTF_FOLDER) && make fclean
	-rm -f $(NAME)

re: fclean all
