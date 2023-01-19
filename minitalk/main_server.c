/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:26:55 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/19 20:00:23 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

t_vars	g_vars;

void	end_num(void)
{
	if (g_vars.result)
		free(g_vars.result);
	g_vars.result = ft_calloc(g_vars.len + 10, sizeof(char));
	g_vars.in_num = 0;
	g_vars.len = 0;
}

void	printn(void)
{
	int	i_val;

	g_vars.i = 0;
	i_val = str_bin(ft_atoi(g_vars.byte));
	if (i_val >= 255 && !g_vars.in_num)
		g_vars.in_num = 1;
	else if (i_val <= 0)
	{
		if (g_vars.pid_mode)
		{
			g_vars.pid_c = ft_atoi(g_vars.result);
			g_vars.pid_mode = 0;
		}
		else
		{
			ft_printf("\n%s\n", g_vars.result);
			g_vars.pid_mode = 1;
		}
		g_vars.k = 0;
	}
	else
		g_vars.result[g_vars.k++] = i_val;
}

void	add_zero(void)
{
	if (g_vars.in_num)
		return (end_num());
	g_vars.byte[g_vars.i++] = '0';
	if (!g_vars.pid_mode)
		kill(g_vars.pid_c, SIGUSR1);
	if (g_vars.i >= BYTE_SIZE)
		printn();
}

void	add_one(void)
{
	if (g_vars.in_num)
	{
		g_vars.len++;
		if (!g_vars.pid_mode)
			kill(g_vars.pid_c, SIGUSR1);
		return ;
	}
	g_vars.byte[g_vars.i++] = '1';
	if (!g_vars.pid_mode)
		kill(g_vars.pid_c, SIGUSR1);
	if (g_vars.i >= BYTE_SIZE)
		printn();
}

int	main(void)
{
	g_vars.i = 0;
	g_vars.k = 0;
	g_vars.in_num = 0;
	g_vars.len = 0;
	g_vars.result = 0;
	g_vars.pid_mode = 1;
	signal(SIGUSR1, add_zero);
	signal(SIGUSR2, add_one);
	ft_printf("\nServer started successfuly!\n\nPID: %d\n-----------\n\n", getpid());
	while (1)
		;
	return (0);
}
