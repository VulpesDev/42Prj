/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:42:23 by tvasilev          #+#    #+#             */
/*   Updated: 2023/04/03 16:23:19 by tvasilev         ###   ########.fr       */
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

void	*monitoring(void *v)
{
	t_phil_vars *vars = v;
	int	endcon;
	int	i;

	endcon = 0;
	while(!endcon)
	{
		i = -1;
		usleep(1000);
		while (++i < vars->data->num_philo && !endcon)
		{
			vars->eat_status[i] += 1;
			if (vars->eat_status[i] >= vars->data->t_die)
			{
				gettimeofday(&vars->data->tv, NULL);
				printf("%lld #%d died\n", calc_secs(vars->data->tv, vars->data->s_time_ms), i+1);
				endcon = 1;
			}
		}
	}
	*vars->stop = 1;
	return NULL;
}

void	set_ids(t_default_data *data, pthread_t *th_id)
{
	int			i;
	t_phil_vars	**vars;
	static int	*eat_status;
	static int	*stop;

	vars = malloc((data->num_philo + 1) * sizeof(t_phil_vars*));
	eat_status = malloc(data->num_philo * sizeof(int));
	memset(eat_status, 0, data->num_philo);
	stop = malloc(sizeof(int));
	*stop = 0;
	i = -1;
	while (++i < data->num_philo)
	{
		vars[i] = malloc(sizeof(t_phil_vars));
		if (!vars[i])
			write(2, "Malloc Error!\n", 15);
		int k = -1;
		while (++k < data->num_forks)
			pthread_mutex_init(&data->th_mutx[k], NULL);
		vars[i]->th_mutx = data->th_mutx;
		vars[i]->data = data;
		vars[i]->ph_id = i;
		vars[i]->eat_status = eat_status;
		vars[i]->stop = stop;
		pthread_create(&th_id[i], NULL, &create_philo, vars[i]);
	}
	vars[i] = malloc(sizeof(t_phil_vars));
	vars[i]->th_mutx = data->th_mutx;
	vars[i]->data = data;
	vars[i]->eat_status = eat_status;
	vars[i]->stop = stop;
	pthread_create(&th_id[i], NULL, &monitoring, vars[i]);
	i = -1;
	while (++i <= data->num_philo)
		pthread_join(th_id[i], NULL);
	i = -1;
	while (++i < data->num_forks)
	{
		pthread_mutex_destroy(&data->th_mutx[i]);
		free(vars[i]);
	}
	free(vars);
	free(eat_status);
}

int	main(int argc, char **argv)
{
	t_default_data	data;
	pthread_t		*th_id;

	if (handle_errors(argc))
		return (0);
	fill_default(&data, argc, argv);
	th_id = malloc((data.num_philo + 2) * sizeof(pthread_t));
	if (!th_id)
		write(2, "Malloc Error!\n", 15);
	gettimeofday(&data.tv, NULL);
	data.s_time_ms = (data.tv.tv_sec) * 1000 + (data.tv.tv_usec) / 1000 ;
	set_ids(&data, th_id);
	free(th_id);
	free(data.th_mutx);
	return (0);
}