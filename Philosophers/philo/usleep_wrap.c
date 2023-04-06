/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:32 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/06 12:56:04 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(long ms, t_var *vars)
{
	long t = 0;
	while (t < ms)
	{
		usleep(1000);
		if (vars->rules->end)
			return (1);
		t+=1;
	}
	return (0);
}