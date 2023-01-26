/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobinary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:57:55 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/20 12:23:47 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	str_bin(int ch)
{
	int	binary;
	int	num;
	int	topower;
	int	dec;

	topower = 0;
	dec = 0;
	binary = ch;
	while (binary)
	{
		num = binary % 10;
		num <<= topower;
		dec += num;
		topower++;
		binary /= 10;
	}
	return (dec);
}

void	wait_func(int w_sig)
{
	if (!w_sig)
		usleep(SLEEP_TIME);
	else
		pause();
}

int	check_pid(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
