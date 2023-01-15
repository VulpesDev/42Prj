#include"minitalk.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	ft_printf("(pid: %d, str: %s)\n", pid, str);
	str = bin_str(str);
	while (*str)
	{
		if (*str == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		str++;
		usleep(100);
	}
	i = BYTE_SIZE + 1;
	while (--i)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
	return (0);
}