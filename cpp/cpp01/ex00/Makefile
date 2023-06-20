# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/06/20 12:50:14 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = zombie

SRC = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -g3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all