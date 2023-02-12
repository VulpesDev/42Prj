/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:42:23 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/12 14:40:14 by tvasilev         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_default_data	data;

	if (!handle_errors(argc, argv))
		return (0);
	fill_default(&data, argc, argv);
	printf("nump:%d\nnumf:%d\ntd:%d\nte:%d\nts:%d\nnbeme:%d\n",
		data.num_philo, data.num_forks, data.t_die, data.t_eat,
		data.t_sleep, data.ec_eat);
	return (0);
}