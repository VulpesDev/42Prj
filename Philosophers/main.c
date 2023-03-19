/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:42:23 by tvasilev          #+#    #+#             */
/*   Updated: 2023/03/19 17:45:26 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_default(t_default_data *data, int argc, char **argv)
{
	data->num_philo = ft_atoi(argv[1]);
	data->num_forks = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->ec_eat = ft_atoi(argv[5]);
	data->th_mutx = malloc(data->num_forks * sizeof(pthread_mutex_t));
	if (!data->th_mutx)
		write(2, "Malloc Error!\n", 15);
}

void	*create_philo(void *v)
{
	t_phil_vars *vars = v;
	ph_eat(vars);
	return NULL;
}

void	set_ids(t_default_data *data, pthread_t *th_id)
{
	int			i;
	t_phil_vars	*vars;

	i = -1;
	while (++i < data->num_philo)
	{
		vars = malloc(sizeof(t_phil_vars));
		if (!vars)
			write(2, "Malloc Error!\n", 15);
		int k = -1;
		while (++k < data->num_forks)
			pthread_mutex_init(&data->th_mutx[k], NULL);
		vars->th_mutx = data->th_mutx;
		vars->data = data;
		vars->ph_id = i;
		pthread_create(th_id, NULL, &create_philo, vars);
	}

	i = -1;
	while (++i < data->num_philo)
		pthread_join(th_id[i], NULL);
	i = -1;
	while (++i < data->num_forks)
		pthread_mutex_destroy(&data->th_mutx[i]);
}
//*put starvation variable in the var that each philosopher has
int	main(int argc, char **argv)
{
	t_default_data	data;
	pthread_t		*th_id;

	if (handle_errors(argc))
		return (0);
	fill_default(&data, argc, argv);
	th_id = malloc(data.num_philo * sizeof(pthread_t));
	if (!th_id)
		write(2, "Malloc Error!\n", 15);
	gettimeofday(&data.tv, NULL);
	data.s_time_ms = (data.tv.tv_sec) * 1000 + (data.tv.tv_usec) / 1000 ;
	set_ids(&data, th_id);
	free(th_id);
	free(data.th_mutx);
	return (0);
}