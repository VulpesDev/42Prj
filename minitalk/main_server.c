#include"minitalk.h"

int	i;

void	printn()
{
	ft_printf("\n");
	i = 0;
}

void	add_zero()
{
	ft_printf("0");
	i++;
	if (i >= BYTE_SIZE)
		printn();
}

void	add_one()
{
	ft_printf("1");
	i++;
	if (i >= BYTE_SIZE)
		printn();
}

int	main(void)
{
	i = 0;
	signal(SIGUSR1, add_zero);
	signal(SIGUSR2, add_one);
	ft_printf("\nServer started successfuly!\n\nPID: %d\n-----------\n\n", getpid());
	while (1)
	{
		//pause();
	}
	
	return (0);
}