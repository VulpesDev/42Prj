gcc_sw =

libft:	main
	ar -cvq libft.a *.o
main: main.o libft.h ft_strchr.o ft_strrchr.o\
	ft_isalpha.o ft_isdigit.o ft_isalnum.o\
	ft_isprint.o ft_tolower.o ft_toupper.o\
	ft_isascii.o ft_strlen.o ft_memset.o\
	ft_bzero.o ft_memcpy.o ft_memmove.o\
	ft_rev_memcpy.o ft_strncmp.o ft_memchr.o\
	ft_memcmp.o ft_strnstr.o ft_strlcpy.o ft_strlcat.o\
	ft_atoi.o ft_calloc.o ft_strdup.o
	cc -o main main.o ft_strchr.o \
	ft_strrchr.o ft_isalpha.o \
	ft_isdigit.o ft_isalnum.o ft_isprint.o \
	ft_tolower.o ft_toupper.o ft_isascii.o \
	ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o \
	ft_memmove.o ft_rev_memcpy.o ft_strncmp.o ft_memchr.o \
	ft_memcmp.o ft_strnstr.o ft_strlcpy.o ft_strlcat.o \
	ft_atoi.o ft_calloc.o ft_strdup.o

clean:
	rm *.o main

main.o: main.c libft.h
	cc $(gcc_sw) -c main.c
ft_strchr.o: ft_strchr.c libft.h
	cc $(gcc_sw) -c ft_strchr.c
ft_strrchr.o: ft_strrchr.c libft.h
	cc $(gcc_sw) -c ft_strrchr.c
ft_isalpha.o: ft_isalpha.c libft.h
	cc $(gcc_sw) -c ft_isalpha.c
ft_isdigit.o: ft_isdigit.c libft.h
	cc $(gcc_sw) -c ft_isdigit.c
ft_isalnum.o: ft_isalnum.c libft.h
	cc $(gcc_sw) -c ft_isalnum.c
ft_isprint.o: ft_isprint.c libft.h
	cc $(gcc_sw) -c ft_isprint.c
ft_tolower.o: ft_tolower.c libft.h
	cc $(gcc_sw) -c ft_tolower.c
ft_toupper.o: ft_toupper.c libft.h
	cc $(gcc_sw) -c ft_toupper.c
ft_isascii.o: ft_isascii.c libft.h
	cc $(gcc_sw) -c ft_isascii.c
ft_strlen.o: ft_strlen.c libft.h
	cc $(gcc_sw) -c ft_strlen.c
ft_memset.o: ft_memset.c libft.h
	cc $(gcc_sw) -c ft_memset.c
ft_bzero.o: ft_bzero.c libft.h
	cc $(gcc_sw) -c ft_bzero.c
ft_memcpy.o: ft_memcpy.c libft.h
	cc $(gcc_sw) -c ft_memcpy.c
ft_memmove.o: ft_memset.c libft.h
	cc $(gcc_sw) -c ft_memmove.c
ft_rev_memcpy.o: ft_rev_memcpy.c libft.h
	cc $(gcc_sw) -c ft_rev_memcpy.c
ft_strncmp.o: ft_strncmp.c libft.h
	cc $(gcc_sw) -c ft_strncmp.c
ft_memchr.o: ft_memchr.c libft.h
	cc $(gcc_sw) -c ft_memchr.c
ft_memcmp.o: ft_memcmp.c libft.h
	cc $(gcc_sw) -c ft_memcmp.c
ft_strnstr.o: ft_strnstr.c libft.h
	cc $(gcc_sw) -c ft_strnstr.c
ft_strlcpy.o: ft_strlcpy.c libft.h
	cc $(gcc_sw) -c ft_strlcpy.c
ft_strlcat.o: ft_strlcat.c libft.h
	cc $(gcc_sw) -c ft_strlcat.c
ft_atoi.o: ft_atoi.c libft.h
	cc $(gcc_sw) -c ft_atoi.c
ft_calloc.o: ft_calloc.c libft.h
	cc $(gcc_sw) -c ft_calloc.c
ft_strdup.o: ft_strdup.c libft.h
	cc $(gcc_sw) -c ft_strdup.c