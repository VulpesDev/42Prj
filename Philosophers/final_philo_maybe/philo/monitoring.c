/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:20:53 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/17 16:16:23 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_ate(t_var **var)
{
	int	i;

	i = -1;
	while (++i < (*var)->rules->num_philo)
	{
		if ((*var)->philo[i].times_ate < (*var)->rules->num_eat)
			return (0);
	}
	return (1);
}

void	monitor(t_var **var)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < (*var)->rules->num_philo)
		{
			if ((int)(timestamp_ms((*var)->rules->time_start)
				- (*var)->philo[i].hunger) > (*var)->rules->time_die)
			{
				(*var)->rules->end = 1;
				message(timestamp_ms((*var)->rules->time_start),
					&(*var)->philo[i], " died\n");
				return ;
			}
			else if ((*var)->rules->has_eat && all_ate(var))
			{
				(*var)->rules->end = 1;
				return ;
			}
		}
	}
}

void	*monitoring(void *vars)
{
	t_var	*var;

	var = (t_var *)vars;
	monitor(&var);
	return (NULL);
}
