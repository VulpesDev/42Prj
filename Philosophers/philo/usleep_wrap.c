/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:32 by tvasilev          #+#    #+#             */
/*   Updated: 2023/03/26 16:23:51 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(__useconds_t usec, t_phil_vars* vars)
{
	__useconds_t t = 0;
	while (t <= usec)
	{
		usleep(1);
		if (*vars->stop)
			return (0);
		t+=1;
	}
	return (0);
}