# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2022/12/18 17:53:23 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchari_fd.c ft_puthexl_fd.c ft_puthexu_fd.c\
ft_puthexu_fd.c ft_putnbri_fd.c ft_putp_fd.c ft_putp_tohex_fd.c\
ft_putstri_fd.c ft_putstri_fd.c ft_putusnbr.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

libft:
	cd Lib && make all
.c.o: 
	cc -Wall -Wextra -Werror $(SRC) -c

$(NAME): $(OBJ)
	ar -cvq $(NAME) $(OBJ)

clean:
	cd Lib && make clean
	-rm -f *.o

fclean: clean
	cd Lib && make fclean
	-rm -f $(NAME)

re: fclean all
