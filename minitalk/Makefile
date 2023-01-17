# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/01/17 12:12:40 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME_SERVER = server

SRC_SERVER = main_server.c tobinary.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)

NAME_CLIENT = client

SRC_CLIENT = main_client.c tobinary.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

PRINTF_NAME = libftprintf.a

LIBFT_NAME = libft.a

PRINTF_FOLDER = ./ft_printf

LIBFT_FOLDER = ./libft

all: $(NAME_CLIENT) $(NAME_SERVER) 

.c.o:
	$(CC) -O3 -c $< -o $@ -g

libft_ftprintf:
	cd $(PRINTF_FOLDER) && make all
	cd $(LIBFT_FOLDER) && make all

$(NAME_SERVER): $(OBJ_SERVER) libft_ftprintf
	$(CC) $(OBJ_SERVER) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) libft_ftprintf
	$(CC) $(OBJ_CLIENT) $(PRINTF_FOLDER)/$(PRINTF_NAME) $(LIBFT_FOLDER)/$(LIBFT_NAME) -o $(NAME_CLIENT)

clean:
	cd $(PRINTF_FOLDER) && make clean
	cd $(LIBFT_FOLDER) && make clean
	-rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	cd $(PRINTF_FOLDER) && make fclean
	cd $(LIBFT_FOLDER) && make fclean
	-rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
