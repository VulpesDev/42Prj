/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:43:46 by tvasilev          #+#    #+#             */
/*   Updated: 2023/03/21 13:29:48 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int calc_secs(struct timeval tv, long long s_time_ms)
{
	return (((tv.tv_sec)*1000+(tv.tv_usec)/1000)-s_time_ms);
}

void	ph_think(void *v)
{
	t_phil_vars *vars = v;
	gettimeofday(&vars->data->tv, NULL);
	printf("%lld #%ld is thinking\n", calc_secs(vars->data->tv, vars->data->s_time_ms), vars->ph_id+1);
}

void	ph_sleep(void *v)
{
	t_phil_vars *vars = v;
	gettimeofday(&vars->data->tv, NULL);
	pthread_mutex_unlock(&vars->th_mutx[vars->ph_id]);
	if ((int)vars->ph_id >= vars->data->num_philo-1)
		pthread_mutex_unlock(&vars->th_mutx[0]);
	else
		pthread_mutex_unlock(&vars->th_mutx[vars->ph_id + 1]);
	if (*vars->stop)
		return ;
	printf("%lld #%ld is sleeping\n",calc_secs(vars->data->tv, vars->data->s_time_ms), vars->ph_id+1);
	usleep(1000*vars->data->t_sleep);
	ph_eat(vars);
}

void	ph_eat(void *v)
{
	t_phil_vars *vars = v;
	if (*vars->stop)
		return ;
	gettimeofday(&vars->data->tv, NULL);
	ph_think(vars);
	pthread_mutex_lock(&vars->th_mutx[vars->ph_id]);
	if (*vars->stop)
		return ph_sleep(vars);
	printf("%lld #%ld has taken a fork\n", calc_secs(vars->data->tv, vars->data->s_time_ms), vars->ph_id+1);
	if ((int)vars->ph_id >= vars->data->num_philo-1)
		pthread_mutex_lock(&vars->th_mutx[0]);
	else
		pthread_mutex_lock(&vars->th_mutx[vars->ph_id + 1]);
	if (*vars->stop)
		return ph_sleep(vars);
	printf("%lld #%ld has taken a fork\n", calc_secs(vars->data->tv, vars->data->s_time_ms), vars->ph_id+1);
	printf("%lld #%ld is eating\n", calc_secs(vars->data->tv, vars->data->s_time_ms), vars->ph_id+1);
	vars->eat_status[vars->ph_id] = 0;
	usleep(1000*vars->data->t_eat);
	ph_sleep(vars);
}