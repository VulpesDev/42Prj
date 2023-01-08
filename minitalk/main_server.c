#include"libft/libft.h"
#include"ft_printf/ft_printf.h"
#include <sys/types.h>
#include <unistd.h>


int	main(void)
{
	ft_printf("\nServer started successfuly!\n\nPID: %d\n-----------\n\n", getpid());
	return (0);
}