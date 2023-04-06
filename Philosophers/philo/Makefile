# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/04/06 10:57:15 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = philo

SRC = handle_errors.c libft.c main.c philosopher_actions.c usleep_wrap.c utils.c monitoring.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) -O3 -c $< -o $@ -g

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all
