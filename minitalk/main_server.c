#include"minitalk.h"

int	i;
char	byte[BYTE_SIZE];
int	in_num;
int	len;
char	*result;
int	k;

void	end_num()
{
	result = malloc((len + 10) * sizeof(char));
	in_num = 0;
	len = 0;
}

void	printn()
{
	int	i_val;

	i_val = str_bin(ft_atoi(byte));
	if (i_val >= 255)
		in_num = 1;
	if (!in_num)
	{
		ft_printf("%c\n", i_val);
		result[k++] = i_val;
	}
	if (i_val <= 0)
	{
		ft_printf("%s\n", result);
		k = 0;
	}
	i = 0;
}

void	add_zero()
{
	if (in_num)
		return end_num();
	byte[i++] = '0';
	if (i >= BYTE_SIZE )
		printn();
}

void	add_one()
{
	if(in_num)
	{
		len++;
	}
	else{
	byte[i++] = '1';
	if (i >= BYTE_SIZE )
		printn();
	}
	
}

int	main(void)
{
	i = 0;
	k = 0;
	in_num = 0;
	len = 0;
	result = 0;
	signal(SIGUSR1, add_zero);
	signal(SIGUSR2, add_one);
	ft_printf("\nServer started successfuly!\n\nPID: %d\n-----------\n\n", getpid());
	while (1)
	{
		//pause();
	}
	
	return (0);
}