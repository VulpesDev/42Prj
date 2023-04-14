/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:20:58 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/14 16:41:04 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(int milliseconds, t_philo *philo, const char *str)
{
	printf("%d #%d %s\n", milliseconds, philo->id + 1, str);
}

int	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((int)((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000));
}

int	timestamp_ms(int program_start)
{
	return (get_time_ms() - program_start);
}

int	ft_sleep(t_rules *rules, int ms)
{
	int	t;

	t = 0;
	while (t < ms)
	{
		if (rules->end)
			return (1);
		t += 50;
		usleep(50000);
	}
	return (0);
}
