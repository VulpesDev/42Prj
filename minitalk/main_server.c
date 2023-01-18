/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:26:55 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/18 16:50:22 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	i;
char	byte[BYTE_SIZE];
int	in_num;
int	len;
char	*result;
int	k;
int	pid_mode;
int	pid_c;

void	end_num()
{
	if (result)
		free(result);
	result = ft_calloc(len + 10 ,sizeof(char));
	in_num = 0;
	len = 0;
}

void	printn()
{
	int	i_val;

	i = 0;
	i_val = str_bin(ft_atoi(byte));
	if (i_val >= 255 && !in_num)
		in_num = 1;
	else if (i_val <= 0)
	{
		if (pid_mode)
		{
			pid_c = ft_atoi(result);
			ft_printf("\npid:%i\n", pid_c);
		}
		else
			ft_printf("\n%s\n", result);
		k = 0;
		pid_mode = 0;
	}
	else
	{
		result[k++] = i_val;
	}
	ft_printf("\n");
}

void	add_zero()
{
	if (in_num)
		return end_num();
	ft_printf("0");
	byte[i++] = '0';
	if (i >= BYTE_SIZE )
		printn();
}

void	add_one()
{
	if(in_num)
	{
		len++;
		return ;
	}
	ft_printf("1");
	byte[i++] = '1';
	// usleep(50);
	// if (!pid_mode)
	// 	kill(pid_c, SIGUSR1);
	if (i >= BYTE_SIZE )
		printn();
}

int	main(void)
{
	i = 0;
	k = 0;
	in_num = 0;
	len = 0;
	result = 0;
	pid_mode = 1;
	signal(SIGUSR1, add_zero);
	signal(SIGUSR2, add_one);
	ft_printf("\nServer started successfuly!\n\nPID: %d\n-----------\n\n", getpid());
	while (1)
		;
	
	return (0);
}