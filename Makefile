# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2022/12/08 17:14:46 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

Cflags = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_strchr.c ft_strrchr.c\
        ft_isalpha.c ft_isdigit.c ft_isalnum.c\
        ft_isprint.c ft_tolower.c ft_toupper.c\
        ft_isascii.c ft_strlen.c ft_memset.c\
	 ft_bzero.c ft_memcpy.c ft_memmove.c\
        ft_rev_memcpy.c ft_strncmp.c ft_memchr.c\
        ft_memcmp.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c\
	ft_atoi.c ft_calloc.c ft_strdup.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -cvq libft.a $(OBJ)

clean:
	-rm -f *.o

fclean: clean
	-rm -f libft.a

re: fclean all	
