# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/01/08 14:23:47 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME_SERVER = server

SRC = main.c

OBJ = $(SRC:.c=.o)

PRINTF_NAME = libftprintf.a

LIBFT_NAME = libft.a

PRINTF_FOLDER = ./ft_printf

LIBFT_FOLDER = ./libft

all: $(NAME_SERVER)

.c.o:
	$(CC) -O3 -c $< -o $@ -g

$(NAME_SERVER): $(OBJ)
	cd $(PRINTF_FOLDER) && make all
	cd $(LIBFT_FOLDER) && make all
	$(CC) $(OBJ) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME) -o $(NAME_SERVER)

clean:
	cd $(PRINTF_FOLDER) && make clean
	cd $(LIBFT_FOLDER) && make clean
	-rm -f $(OBJ)

fclean: clean
	cd $(PRINTF_FOLDER) && make fclean
	cd $(LIBFT_FOLDER) && make fclean
	-rm -f $(NAME_SERVER)

re: fclean all
