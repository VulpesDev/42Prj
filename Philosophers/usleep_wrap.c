/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_wrap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:32 by tvasilev          #+#    #+#             */
/*   Updated: 2023/03/19 16:46:21 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(__useconds_t usec)
{
	__useconds_t t = 0;
	while (t+=5000 < usec)
	{
		usleep(5000);
	}
	return (0);
}