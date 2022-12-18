# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2022/12/18 17:12:14 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchari_fd.c ft_puthexl_fd.c ft_puthexu_fd.c\
ft_puthexu_fd.c ft_putnbri_fd.c ft_putp_fd.c ft_putp_tohex_fd.c\
ft_putstri_fd.c ft_putstri_fd.c ft_putusnbr.c

OBJ = libft $(SRC:.c=.o)

all: $(NAME)

libft:
	cd Lib | make
.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I .

$(NAME): $(OBJ)
	ar -cvq libft.a $(OBJ)

clean:
	-rm -f *.o

fclean: clean
	-rm -f libft.a

re: fclean all
