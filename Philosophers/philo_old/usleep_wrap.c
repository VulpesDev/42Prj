/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:32 by tvasilev          #+#    #+#             */
/*   Updated: 2023/03/30 12:50:22 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(__useconds_t usec, t_phil_vars* vars)
{
	__useconds_t t = 0;
	while (t < usec)
	{
		usleep(5000);
		if (*vars->stop)
			return (1);
		t+=5000;	
	}
	return (0);
}