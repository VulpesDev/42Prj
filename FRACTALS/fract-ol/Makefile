# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/01/05 16:11:20 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = fractol

SRC = mandelbrot.c draw.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g

$(NAME): $(OBJ)
	cd mlx_linux && ./configure
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all
