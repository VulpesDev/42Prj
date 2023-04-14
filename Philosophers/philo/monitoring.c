/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:20:53 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/14 16:40:12 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			else if ((*var)->rules->has_eat
				&& (*var)->philo[i].times_ate >= (*var)->rules->num_eat)
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
