#include"minitalk.h"

int	can_send;

void	send_signal_special(int pid, int sig, int w_sig)
{
	int	i;

	i = BYTE_SIZE;
	while (i)
	{
		if (can_send || !w_sig)
		{
			if (!sig)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			can_send = 0;
		}
		if (w_sig)
			pause();
		else
			usleep(50000);
	}
}

void	send_signal(int pid, char *str, int w_sig)
{
	int		i;
	int		limit;
	char	*sdup;

	i = -1;
	sdup = ft_strdup(str);
	while (sdup[++i])
	{
		limit = BYTE_SIZE;
		while (limit)
		{
			if (can_send || !w_sig)
			{
				if (sdup[i] & 128)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				sdup[i] = sdup[i] << 1;
				limit--;
				can_send = 0;
			}
			if (w_sig)
			pause();
			else
			usleep(50000);
		}
	}
	send_signal_special(pid, 0, w_sig);
}

void	send_signal_n(int pid, int n, int w_sig)
{
	while (n)
	{
		if (can_send || !w_sig)
		{
			ft_printf("n:%d\n", n);
			kill(pid, SIGUSR2);
			can_send = 0;
			n--;
		}
		if (w_sig)
			pause();
		else
			usleep(50000);
	}
	kill(pid, SIGUSR1);
}

void	send_confirm()
{
	ft_printf("\nReceived confirmation!\n");
	can_send = 1;
}

int	main(int argc, char **argv)
{
	int		pid;

	signal(SIGUSR1, send_confirm);
	can_send = 1;
	pid = ft_atoi(argv[1]);
	ft_printf("(pid: %d, str: %s)\n", pid, argv[2]);
	ft_printf("len of str: %d\n", ft_strlen(argv[2]));
	
	send_signal_special(pid, 1, 0);
	send_signal_n(pid, ft_strlen(ft_itoa(pid)) + 1, 0);
	send_signal(pid, ft_itoa(pid), 0);
	ft_printf("\npid finished!\n");
	can_send = 1;
	send_signal_special(pid, 1, 0);
	ft_printf("\nspecial sent\n");
	send_signal_n(pid, ft_strlen(argv[2]) + 1, 0);
	send_signal(pid, argv[2], 0);
	return (0);
}