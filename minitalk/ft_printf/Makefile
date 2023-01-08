SRC = ft_printf.c ft_putchari_fd.c ft_puthexl_fd.c ft_puthexu_fd.c\
ft_puthexu_fd.c ft_putnbri_fd.c ft_putp_fd.c ft_putp_tohex_fd.c\
ft_putstri_fd.c ft_putstri_fd.c ft_putusnbr.c
OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

NAME = libftprintf.a

$(NAME) :	$(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)