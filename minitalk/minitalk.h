#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# define BYTE_SIZE 8

typedef struct s_byte{
	char	str[BYTE_SIZE + 1];
	int		index;
	char	result[10000];
	int		resulti;
}				t_byte;

char	*bin_str(char *ch);

int	str_bin(int ch);

#endif