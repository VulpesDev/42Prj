# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 16:50:22 by tvasilev          #+#    #+#              #
#    Updated: 2023/02/04 15:38:51 by tvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strchr.c ft_strrchr.c\
        ft_isalpha.c ft_isdigit.c ft_isalnum.c\
        ft_isprint.c ft_tolower.c ft_toupper.c\
        ft_isascii.c ft_strlen.c ft_memset.c\
         ft_bzero.c ft_memcpy.c ft_memmove.c\
         ft_strncmp.c ft_memchr.c\
        ft_memcmp.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c\
        ft_atoi.c ft_calloc.c ft_strdup.c\
        ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
        ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
            ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
            ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME) bonus

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I .

$(NAME): $(OBJ)
	ar -crs libft.a $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar -crs libft.a $(OBJ) $(OBJ_BONUS)

clean:
	-rm -f *.o

fclean: clean
	-rm -f libft.a

re: fclean all
