/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:56:39 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/19 20:01:53 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	g_can_send;

void	send_signal_special(int pid, int sig, int w_sig)
{
	int	i;

	i = BYTE_SIZE;
	while (i)
	{
		if (g_can_send || !w_sig)
		{
			if (!sig)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			g_can_send = 0;
		}
		if (!w_sig)
			usleep(150);
		else
			pause();
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
		usleep(1);
		limit = BYTE_SIZE;
		while (limit)
		{
			if (g_can_send || !w_sig)
			{
				if (sdup[i] & 128)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				sdup[i] = sdup[i] << 1;
				limit--;
				g_can_send = 0;
			}
			if (!w_sig)
				usleep(150);
			else
				pause();
		}
	}
	free(sdup);
	send_signal_special(pid, 0, w_sig);
}

void	send_signal_n(int pid, int n, int w_sig)
{
	while (n)
	{
		if (g_can_send || !w_sig)
		{
			kill(pid, SIGUSR2);
			g_can_send = 0;
			n--;
		}
		if (!w_sig)
			usleep(150);
		else
			pause();
	}
	kill(pid, SIGUSR1);
}

void	send_confirm(void)
{
	g_can_send = 1;
}

int	main(int argc, char **argv)
{
	int		pid;

	signal(SIGUSR1, send_confirm);
	g_can_send = 1;
	pid = ft_atoi(argv[1]);
	ft_printf("(pid: %d, str: %s)\n", pid, argv[2]);
	ft_printf("len of str: %d\n", ft_strlen(argv[2]));
	send_signal_special(pid, 1, 0);
	send_signal_n(pid, ft_strlen(ft_itoa(getpid())) + 1, 0);
	send_signal(pid, ft_itoa(getpid()), 0);
	g_can_send = 1;
	send_signal_special(pid, 1, 1);
	send_signal_n(pid, ft_strlen(argv[2]) + 1, 1);
	send_signal(pid, argv[2], 1);
	return (0);
}
