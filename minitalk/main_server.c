#include"minitalk.h"

t_byte byte;

void	end_of_byte()
{
	byte.result[byte.resulti++] = str_bin(ft_atoi(byte.str));
	if (ft_atoi(byte.str) == 0)
	{
		ft_printf("%s\n", byte.result);
		byte.resulti = 0;
	}
	byte.index = 0;
}

void	add_zero()
{
	byte.str[byte.index++] = '0';
	if (byte.index == BYTE_SIZE)
	{
		byte.str[byte.index] = '\0';
		end_of_byte();
	}
}

void	add_one()
{
	byte.str[byte.index++] = '1';
	if (byte.index == BYTE_SIZE)
	{
		byte.str[byte.index] = '\0';
		end_of_byte();
	}
}

int	main(void)
{
	byte.index = 0;
	byte.resulti = 0;
	signal(SIGUSR1, add_zero);
	signal(SIGUSR2, add_one);
	ft_printf("\nServer started successfuly!\n\nPID: %d\n-----------\n\n", getpid());
	while (1)
	{
		pause();
	}
	
	return (0);
}