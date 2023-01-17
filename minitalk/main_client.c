#include"minitalk.h"

void	send_signal_special(int pid, int sig)
{
	int	i;

	i = BYTE_SIZE + 1;
	while (--i)
	{
		if (!sig)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	send_signal(int pid, char *str)
{
	int		i;
	int		limit;
	char	*sdup;

	i = -1;
	sdup = ft_strdup(str);
	while (sdup[++i])
	{
		limit = BYTE_SIZE + 1;
		while (--limit)
		{
			if (sdup[i] & 128)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			sdup[i] = sdup[i] << 1;
			usleep(100);
		}
	}
	send_signal_special(pid, 0);
}

void	send_signal_n(int pid, int n)
{
	while (n--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
	kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int		pid;

	pid = ft_atoi(argv[1]);
	ft_printf("(pid: %d, str: %s)\n", pid, argv[2]);
	send_signal_special(pid, 1);
	ft_printf("len of str: %d\n", ft_strlen(argv[2]));
	send_signal_n(pid, ft_strlen(argv[2]) + 1);
	send_signal(pid, argv[2]);
	return (0);
}