/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:56:39 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/20 12:24:37 by tvasilev         ###   ########.fr       */
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
		wait_func(w_sig);
	}
}

void	send_signal(int pid, char *str, int w_sig)
{
	t_send_vars	vars;

	vars.i = -1;
	vars.sdup = ft_strdup(str);
	while (vars.sdup[++vars.i])
	{
		usleep(1);
		vars.limit = BYTE_SIZE;
		while (vars.limit)
		{
			if (g_can_send || !w_sig)
			{
				if (vars.sdup[vars.i] & 128)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				vars.sdup[vars.i] = vars.sdup[vars.i] << 1;
				vars.limit--;
				g_can_send = 0;
			}
			wait_func(w_sig);
		}
	}
	free(vars.sdup);
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
		wait_func(w_sig);
	}
	kill(pid, SIGUSR1);
}

void	send_confirm(int a)
{
	g_can_send = 1;
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc < 3)
		return (ft_printf("Incorrect input!\n"));
	signal(SIGUSR1, send_confirm);
	g_can_send = 1;
	if (!check_pid(argv[1]))
		return (ft_printf("Incorrect pid!\n"));
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
